#ifndef myTypes_h
#define myTypes_h

#include <WString.h>

typedef struct {
  int valid;                        

  //WLAN
  char SSID[31];
  char password[64];

  //Abstandssensor
  float data_startwert;    
  float data_brennwert;
  float data_zustandszahl;
  int data_impulszaehler;

  //eigene API
  int data_eigenapi_check;
  char data_eigenapi_server[31];
  char data_eigenapi_pfad[81];
  int data_eigenapi_port;
  int data_eigenapi_anz_aufrufe;

  //Web API
  int data_webapi_check;

  //OTA
  int data_ota_check;

  //MQTT
  int data_mqtt_check;
  char data_mqtt_server[31];
  char data_mqtt_benutzer[51];
  char data_mqtt_passwort[51];
  char data_mqtt_impuls_topic[51];
  char data_mqtt_zaehlerstand_topic[51];
  int data_mqtt_port;  
  
  //NTP
  char data_ntp_server[50];

  char data_sensorname[20];
  
  int data_impulsgeber;

} configData_t;

#endif
