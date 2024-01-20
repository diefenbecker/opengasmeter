//**********************************************
// MQTT
//**********************************************
void mqtt_api() {
    
  String clientName;
  clientName += "esp8266-";
  clientName += macAdresse;
  
  Serial.print("Client-Name: ");
  Serial.println(clientName);

  Serial.print("MQTT-Broker Server: ");
  Serial.println(cfg.data_mqtt_server);

  int mqtt_port=0;
  //schauen ob MQTT-Port gesetzt wurde und ggf. nutzen
  if (cfg.data_mqtt_port!=0) {
    mqtt_port=cfg.data_mqtt_port;      
    Serial.print("MQTT-Broker Port: ");
    Serial.println(cfg.data_mqtt_port);
  } else {
    mqtt_port=1883;      
    Serial.println("MQTT-Broker Port nicht definiert. Nutze Standardport 1883");
    Serial.println(cfg.data_mqtt_port);
  }

  PubSubClient client(cfg.data_mqtt_server, mqtt_port, callback, wifiClient);
  //client.setServer(cfg.data_mqtt_server, 1883);

  //if (client.connect((char*) clientName.c_str())) {
  if (client.connect((char*) clientName.c_str(), cfg.data_mqtt_benutzer, cfg.data_mqtt_passwort)) {
    Serial.println("Verbunden zu MQTT-Broker");
    
    //Impuls senden
    Serial.print("Topic fuer Impuls ist: ");
    Serial.println(cfg.data_mqtt_impuls_topic);
    if (client.publish(cfg.data_mqtt_impuls_topic, "1", true)) {
      Serial.print("Publish erfolgreich: ");
      Serial.println(1);
    }
    else {
      Serial.println("Publish fehlgeschlagen");
    }
    //Zaehlerstand senden
    Serial.print("Topic fuer Zaehlerstand ist: ");
    Serial.println(cfg.data_mqtt_zaehlerstand_topic);
    if (client.publish(cfg.data_mqtt_zaehlerstand_topic, String(verbrauch/100).c_str(), true)) {
      Serial.print("Publish erfolgreich: ");
      Serial.println(1);
    }
    else {
      Serial.println("Publish fehlgeschlagen");
    }


  }
  else {
    Serial.println("Verbindung zum MQTT-Broker fehlgeschlagen");
  }  
}
