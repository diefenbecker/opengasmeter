//********************************************************
// Ruft per HTTP-Post eine Webseite auf und übergibt
// verschiedene Werte per Argument
//********************************************************
void web_api() {
  
  String url = "/heimautomatisierung/gaszaehler.php";
  url += "?mac=";
  url += macAdresse;
  url += "&ip=";
  url += ipAdresse;
  url += "&fw=";
  url += fw_version;
  url += "&brennwert=";
  url += cfg.data_brennwert/100;
  url += "&zustandszahl=";
  url += cfg.data_zustandszahl/100;
  url += "&impulsgeber=";
  url += cfg.data_impulsgeber;

  if(DEBUG) {
    Serial.println("");
    Serial.print("URL-Anfrage zu Web API: ");
    Serial.println(url);
  }
  
  WiFiClient client;
  HTTPClient http;
  http.begin(client, "http://www.bubux.de/" + url); 
  int httpCode = http.GET();
  if(httpCode > 0) {
    if (httpCode == HTTP_CODE_OK) {
      Serial.println("Impuls an DB gesendet");
    }
  } else {
    Serial.printf("[HTTP] GET... fehlgeschlagen, Fehler: %s\n", http.errorToString(httpCode).c_str());
  }
  http.end();
  client.stop();
  
}
