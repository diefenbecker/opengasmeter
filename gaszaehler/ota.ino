//**********************************************
// OTA-Update
//**********************************************
void checkForUpdates() {
  
  currentMillisOta = millis();
  if (currentMillisOta - startMillisOta >= (ota_zeit * 1000)) {
    
    startMillisOta = currentMillisOta;
  
    String mac = macAdresse;
    String fwURL = String( fw_url );
    fwURL.concat( mac );
    String fwVersionURL = fwURL;
    fwVersionURL.concat( ".version" );
    
    Serial.println( "Suche nach Firmware-Update..." );
    Serial.print( "MAC-Adresse: " );
    Serial.println( mac );
    Serial.print( "URL zur Firmware: " );
    Serial.println( fwVersionURL );
    

    WiFiClient client;

    ESPhttpUpdate.onStart(update_started);
    ESPhttpUpdate.onEnd(update_finished);
    ESPhttpUpdate.onProgress(update_progress);
    ESPhttpUpdate.onError(update_error);

    t_httpUpdate_return ret = ESPhttpUpdate.update(client, fw_url);

    switch (ret) {
      case HTTP_UPDATE_FAILED: Serial.printf("HTTP_UPDATE_FAILD Error (%d): %s\n", ESPhttpUpdate.getLastError(), ESPhttpUpdate.getLastErrorString().c_str()); break;

      case HTTP_UPDATE_NO_UPDATES: Serial.println("HTTP_UPDATE_NO_UPDATES"); break;

      case HTTP_UPDATE_OK: Serial.println("HTTP_UPDATE_OK"); break;
    }
  }
}

void update_started() {
  Serial.println("CALLBACK:  HTTP update process started");
}

void update_finished() {
  Serial.println("CALLBACK:  HTTP update process finished");
}

void update_progress(int cur, int total) {
  Serial.printf("CALLBACK:  HTTP update process at %d of %d bytes...\n", cur, total);
}

void update_error(int err) {
  Serial.printf("CALLBACK:  HTTP update fatal error code %d\n", err);
}
