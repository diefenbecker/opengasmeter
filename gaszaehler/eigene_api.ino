//********************************************************
// Ruft per HTTP-Post eine Webseite auf und uebergibt
// verschiedene Werte per Argument
//********************************************************
void eigene_api() {
  
  String server = cfg.data_eigenapi_server;
  String pfad = cfg.data_eigenapi_pfad;
  String port = String(cfg.data_eigenapi_port);
  String url = "http://" + server + ":" + port + "/" + pfad;

  if(DEBUG) {
    Serial.println("");
    Serial.print("URL-Anfrage zu eigener API: ");
    Serial.println(url);
  }
  
  WiFiClient client;
  HTTPClient http;
  http.begin(client, url); 
  int httpCode = http.GET();
  if(httpCode > 0) {
    if (httpCode == HTTP_CODE_OK) {
      Serial.println("Impuls an eigene API gesendet");
    }
  } else {
    Serial.printf("[HTTP] GET... Fehlgeschlagen, Fehler: %s\n", http.errorToString(httpCode).c_str());
  }
  http.end();
  client.stop();

}
