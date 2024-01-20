#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <ESP8266WebServer.h>
#include <Ticker.h>
#include <EEPROM.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266httpUpdate.h>
#include <Wire.h>
#include <PubSubClient.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <SimpleTimer.h>
#include "myTypes.h"

extern "C" {
  #include "user_interface.h"
}

//********************************************************
// Variablen für Gaswerte
//********************************************************
int dauer;
int impuls = 1;
int impuls_gesamt = 1;
float verbrauch;
float verbrauch_kwh;
unsigned long value = 0;
float startwert;

SimpleTimer timer;


//********************************************************
// Ein- Ausgaenge
//********************************************************
#define led 0
#define reed 2

//********************************************************
// Debug-Ausgabe aktivieren (true/false)
//********************************************************
#define DEBUG true

//********************************************************
// OTA-Variablen
//********************************************************
const char* fw_url = "http://www.bubux.de/heimautomatisierung/ota/gaszaehler/";
int ota_zeit = 3600;
unsigned long startMillisOta;
unsigned long currentMillisOta;

//********************************************************
// MQTT
//********************************************************
void callback(char* topic, byte* payload, unsigned int length) {
  // Eingehende Nachricht verarbeiten
}

//********************************************************
// WEBAPI-Variablen
//********************************************************
int webapi_zeit = 3600;

//********************************************************
// Zeit per NTP holen
//********************************************************
WiFiUDP ntpUDP;
unsigned long currentMillisNTP;
unsigned long startMillisNTP;
const long utcOffsetInSeconds = 7200;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

//********************************************************
// Grundsätzliche Einstellungen
//********************************************************
const int fw_version = 1006;
String anwendungsname = "Gaszaehler";
String apSSID = "WLAN-Gaszaehler";
const int cfgStart = 0;
const int setupTimeOutLimit = 300;        // Zeit die AP bestehen bleibt. War mal 600, jetzt nur noch 5 Minuten

ESP8266WebServer server(80);
WiFiClient wifiClient;
Ticker setupTimeOut_timer;                // Timer um AP zu resetten
configData_t cfg;

//Prüfung ob der EEPROM gelöscht werden soll...aktuell nicht genutzt
int eepromToClear = 0;

//********************************************************
// Globale Variablen
//********************************************************
int webtypeGlob;

uint8_t mac[6];
String stationList = "";
int setupTimeOut = 0;                     // Timeout für AP initialisieren

String macAdresse;
String ipAdresse;
String myHostname;

ADC_MODE(ADC_VCC);
uint32_t freeheap = system_get_free_heap_size();

//Fuer die taegliche Ausfuehrung
bool gesendet_pushover = false;
bool gesendet_mail = false;

//********************************************************
// SETUP
//********************************************************
void setup() {
  Wire.begin();
  
  Serial.begin(115200);
  delay(3000);
  Serial.println("Auf gehts...");

  pinMode(led, OUTPUT);
  pinMode(reed, INPUT);

  //Lade Konfiguration aus EEPROM
  ladekonfig();

  if (cfg.data_sensorname!="") {
    Serial.print("Anwendungsname setzen: ");
    anwendungsname = cfg.data_sensorname;
    Serial.println(anwendungsname);
  }
  
  //Startwert auslesen
  //if (cfg.data_startwert!="") {
    Serial.println("Startwert auslesen ");
    startwert = cfg.data_startwert;
    verbrauch = startwert;
  //}

  if (cfg.data_impulszaehler>1) {
    Serial.println("Bereits gezählte Impulse addieren (nach Sensor-Neustart)");
    if (cfg.data_impulsgeber==0) {
      startwert += float(cfg.data_impulszaehler)*10;
    } else {
      startwert += float(cfg.data_impulszaehler);
    }
    verbrauch = startwert;
  }
  Serial.print("Impulszaehler: ");
  Serial.println(cfg.data_impulszaehler);
  Serial.print("Startwert: ");
  Serial.println(startwert);
  Serial.print("Verbrauch: ");
  Serial.println(verbrauch);


  //Zeit merken um OTA und NTP zeitgesteuert aufzurufen  
  startMillisOta = millis();
  startMillisNTP = millis();
  
  //MAC auslesen und in Variablen schreiben
  WiFi.macAddress(mac);
  macAdresse = macToStr(mac);
  macAdresse.toUpperCase();
  myHostname = macToHostname(mac);

  //Starte WLAN-Verbindung
  starteWLAN();

  //NTP
  //NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);
  timeClient.begin();   //Timer starten
  timeClient.update();  //Zeit mit NTP updaten
  if (DEBUG) Serial.println("Initialales NTP-Update erfolgt");
   
  Serial.println ("Initialisierung abgeschlossen");
  
}

//********************************************************
// LOOP
//********************************************************
void loop() {

  //****************
  //Impulse abfragen
  //****************
  impuls = digitalRead(reed);
  if (impuls == 0 && impuls != impuls_gesamt) {
    value++;
    looprechnen();
    Serial.println("Impuls");

    //**************************
    //Daten an Web API übergeben
    //**************************
    if (cfg.data_webapi_check == 1) {
      web_api();
    }

    //*****************************
    //Daten an eigene API übergeben
    //*****************************
    if (cfg.data_eigenapi_check == 1) {
      eigene_api();
    }

    //**************************
    //MQTT
    //**************************
    if (cfg.data_mqtt_check == 1) {
      mqtt_api();
    }
    
  }
  impuls_gesamt=impuls;

  //**************************
  //OTA-Update prüfen
  //**************************
  if (cfg.data_ota_check == 1) {
    checkForUpdates();
  }

  if (eepromToClear == 1) {
    if (DEBUG) Serial.println("Flag zur Löschung des EEPROM gesetzt!");
    eraseConfig();
    delay(100);
    eepromToClear = 0;
    system_restart();
  }

  //******************
  //WLAN-Status prüfen
  //******************
  if (WiFi.status() == WL_CONNECTED || webtypeGlob == 1) {
    server.handleClient();
    delay(10);
  } else {
    if (DEBUG) Serial.println("WLAN nicht verbunden");
    delay(1000);
    starteWLAN();
  }

  //******************
  //NTP
  //******************
  currentMillisNTP = millis();
  //Alle 30 Minuten refreshen
  if (currentMillisNTP - startMillisNTP >= (1800 * 1000)) {
    startMillisNTP = currentMillisNTP;
    timeClient.update();
    if (DEBUG) Serial.println("NTP-Update erfolgt");
  }
  
}