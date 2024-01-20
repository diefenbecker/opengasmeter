void webHandleRoot() {
  String inhalt;
  float vcc = ESP.getVcc() / 1000.0;
  inhalt  = "<!DOCTYPE html>";
  inhalt += "<html><head><meta charset='utf-8' name='viewport' content='width=device-width, initial-scale=1.0'><title>" + anwendungsname + "</title></head><body style='font-family:verdana;background-color:#B9DFF8;color:#000000;margin:0px'>";
  inhalt += "<p style='background-color:#FFFFFF;color:#000000;padding:20px;padding-left:10px;margin:0px;'><img style='vertical-align: middle; width:40px;' src='data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAACgAAAA1CAMAAAAEaFkaAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAFlUExURWx5jyg8XRwxVEpbd4uVpiE2WFdmgC1AYJCZqSA0V4WQoUxceFdmfx4yVU1deIGMoCs/Xz1PbYqVp05eeSQ4WmNxiWd0i4KNn2VzizdJaDZJZyk9XoKNoR0yVXiEmW16kGJwiJigrjhLaT9RbnqGmm57knJ/lWt4jx4zVpWerlJifDVIZ2d1jEVWc1Bgen2JnCI3WYiSo1RkfmRyiTpMa0BRb19thXOAlYeSpIiTpYGMnx80VlBge52mtCU5Wp+otzJFZEdYdWZ0jFlogT5QbpuktCQ5WiU6WyE1WKuzwJKbq5GbrC1AYTtNa4+ZqXN/lFppglVkfo2XqR0yVGFwiJyksY2XqDBDY2p4j01deT5PbYiSpI2Xp0JUcSA1V5afrZ+ntmNxiH2JnXF+k0ladn6KnkNUcT5QbUpadoWQoiU5Wy9CYio+XoyXqHF+lDlManyInVVlf3qGm4WPoZmismh2jQAAAJ5Dk0AAAAB3dFJOU/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////8AqZ+kZQAAAAlwSFlzAAAOwAAADsABataJCQAAAjFJREFUSEuNlGdX1FAURcMTVOwFFUWwKxbsvXdRVOxiw46Kvd3f7y17kvdGZ8n+kHXvOXtNkplJKulEW9NR7EoM0EGcldJMxO4e9WYgzjZtBuKc8P4nzu3FS/NIgnaxwlLmEwVt4gIkYyFZUIqLcILFpE4hll5aQuzk4lKEmmUURiYup27oozEacQVtzko6pRZX0ZVQKrVI4/SvZkhraBtxgMZYK4NMKQ3Rt8T8i1lXfHz0tUhqrBfZwGhsDAGxi1TZpOtmZmeLGyFuJVP8q9vG4gxagjhMpmy3fQdLsNMiF3eRKCMe7maDPZaZuJdAsegvsccyFfexK/vdkxHWFgdCPMiqhNd2jSkNa6Yim3IoPDnMXnPExKMsyjHE47ac8CjQq6zkJIuCFyc5ddqz4IyKzT2fRXPxnJyP1LmgIqOivzJcTOlS8Qe4XIjdaPry8cvIn6FCDMm5MqqHq+SGVNeYlHCcset2vEGh3KzGmRRX4JYfKZTxaohJ8a7gNo0+EtUdJoU25y5VGutwMy3uUZV3fZ82h8rEPsaUHlDmPIyqV8XmVTJBmcPv+EjF5tyPKXOeRPXUxGcxpzRJmfPcG/+bSfMCia7ghRcvQ3zli/I6yhzv7OkysX6FxhNc8Mbytzq4KFPu/evc9m54Z0OI8j7E/tgaPmg47ROiTLjYy1bzseXVosgnM/3t0fC59jJRvuj1DDDDdPrKlIv6e42mb4zO98kfTG2iyM8pBuPXbwYRkT+w7jqWEcabsQAAAABJRU5ErkJggg=='>&nbsp;&nbsp;";
  inhalt += "<span style='font-size:24px;font-weight:bold;'>" + anwendungsname + "</span>&nbsp;<span style='font-size:12px;font-weight:normal;'>v" + fw_version + "</span></p>";  
  inhalt += "<p style='font-size:18px;font-weight:bold;background-color:#85C5EE;padding-left:10px;padding-top:10px;padding-bottom:10px;margin:0px;'>Startseite</p>";
  inhalt += "<br>";
  inhalt += "<div style='padding-left:10px;padding_right:10px;'>";

  //*******************************
  //Kästchen zur Anzeigen der Werte
  //*******************************
  //Gasverbauch in Kubikmeter
  inhalt += "<div style='float:left; width: 160px; height: 120px; background: #85C5EE; padding: 5px; font-size:20px; vertical-align: middle; text-align: center; margin: 2px;'>";
  inhalt += (float)verbrauch/100;
  inhalt += "<span style='font-size:17px;'>m<sup>3</sup></span><br>";
  inhalt += (float)verbrauch_kwh/100;
  inhalt += "<span style='font-size:17px;'>kWh</span>";
  inhalt += "<p style='width:150px; background: #5EACDF; padding: 5px; font-size:14px; vertical-align: middle; text-align: center; margin-top:46px;'>Gesamtverbrauch</p></div>";
  
  if (cfg.data_webapi_check == 1) {    
    inhalt += "<div style='float:left; width: 160px; height: 120px; background: #ADADAD; padding: 5px; color:#ffffff; font-size:45px; vertical-align: middle; text-align: center; margin: 2px;'>";
    inhalt += "<a href='http://www.bubux.de/heimautomatisierung/gaszaehler_auswertung.php?mac=";
    inhalt += macAdresse;
    inhalt += "&brennwert=";
    inhalt += cfg.data_brennwert/100;
    inhalt += "&zustandszahl=";
    inhalt += cfg.data_zustandszahl/100;
    inhalt += "&zaehlerstand=";
    inhalt += (float)verbrauch/100;
    inhalt += "' target='_BLANK' style='text-decoration:none;'><img style='padding:12px;' src=\"data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAEIAAAA8CAMAAADlopxrAAAABGdBTUEAALGPC/xhBQAAAAFzUkdCAK7OHOkAAAAJcEhZcwAADsAAAA7AAWrWiQkAAAD8UExURUdwTAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAOBZMRsAAABTdFJOUwCr64sIVNeAAfsCFPM4BOcMGDwoyxz+A8MHbFFwMJ+jQBHPfOMJRPdY/SQKXEwTDZN024O2u8AgaAYLEDQVmzm/BZojs3+tUGmmSU1m9mBqZHP4SBL89AAAAdBJREFUSMftlsd22zAQRZ9kSR4yDElVy5Z7d3rvidN7v///L1lIVBKRgAo3XmhW5AHn4nJwAIyAVZWLJWKJWCKKY6ssorYSbPyPWDfJ5iBcbkD0MGcRzqMA8DKHMElrsyoA1XpxLWqzKlC55CinXZ1LwbsitZkUfIjjw4GkcGKVzicVPIhnEbxWune0bl4FN6KdALyv+avgQzTvAECnO03BhUj3GUWyO0XBgYj7APf2AUYbwalQjIgrAPfjdAeA7ZpT4bELcQugc1PS7QCg88ajUIg4AGg0JUm7CUDgqoID8QgguTJ663aywjoUChD1AIi2/i7ltl8hj2hFQNDKtr4kbQSfPAqTCGtHQDAxY1vH+TwrRlg3AdiUK8PMzLwWzQbA3Xz+UXYkWhh6EKa0D/AiO0jH39orm3aPHAw/jN8CVOIs8cnEL/sQv4ZPOwD9dDwSrs14nAM/JEkrAI30n3ltdsRXSdoEOGzOdx+NET9NOgVI2vnxMJ6O+F39LnVPgKhVQHh+Y2pJeid8kfQhIri+4A1/BgNJalWvLdpf9GC4JZ4u3KKc9aiX7HJ6wbfT8o3SwEojPpe3+Fge8W7Z/V4AhO2NGiDgwWqpEKXjYiD+AEWsyWhYQWN3AAAAAElFTkSuQmCC\">";
    inhalt += "<span style='font-size:20px;'></span>";
    inhalt += "<p style='width:150px; background: #676767; padding: 5px; font-size:14px; color:#ffffff; vertical-align: middle; text-align: center; margin-top:1px;text-decoration:none;'>Auswertung</p></a></div>";
  }

  //*******************************
  inhalt += "<div style='clear: both;'></div>";

  inhalt += "<br><br><br>";

  inhalt += "<details>";
  inhalt += "<summary style='background-color:#2e86c1;color:#ffffff;padding:5px;'>Technische Daten</summary>";
  inhalt += "<table style='font-size:14px;'>";

  inhalt += "<tr><td>Systemzeit</td><td>";
  inhalt += timeClient.getFormattedTime();
  //inhalt += timeClient.getHoures();
  //inhalt += ":";
  //inhalt += timeClient.getMinutes();
  //inhalt += ":";
  //inhalt += timeClient.getSeconds();
  //inhalt += "</td></tr>";

  inhalt += "<tr><td>IP-Adresse</td><td>";
  inhalt += ipAdresse;
  inhalt += "</td></tr>";

  inhalt += "<tr><td>MAC-Adresse</td><td>";
  inhalt += macAdresse;
  inhalt += "</td></tr>";

  inhalt += "<tr><td>Spannung am ESP</td><td>";
  inhalt += vcc;
  inhalt += " V</td></tr>";

  inhalt += "<tr><td>Impulsz&auml;hler</td><td>";
  inhalt += cfg.data_impulszaehler;
  inhalt += "</td></tr>";

  inhalt += "<tr><td>WIFI Signal</td><td>";
  inhalt += WiFi.RSSI();
  inhalt += " dBm</td></tr>";

  //  inhalt += "<tr><td>WIFI Qualit&auml;t</td><td>";
  //  inhalt += vcc;
  //  inhalt += " %</td></tr>";

  inhalt += "<tr><td>Freier Heapspeicher</td><td>";
  inhalt += ESP.getFreeHeap();
  inhalt += "</td></tr>";

  inhalt += "<tr><td>Heap Fragmentierung (<50% OK)</td><td>";
  inhalt += ESP.getHeapFragmentation();
  inhalt += "%</td></tr>";

  //inhalt += "<tr><td>Freier Heapspeicher</td><td>";
  //inhalt += freeheap;
  //inhalt += "</td></tr>";

  //inhalt += "<tr><td>Aufrufe eigene API seit Start</td><td>";
  //inhalt += eigenapi_anz_aufrufe;
  //inhalt += "</td></tr>";

  inhalt += "<tr><td>Eigene API</td><td>";
  if (cfg.data_eigenapi_check == 1) {
    inhalt += "<span style='color:#008700'>aktiviert</span>"; // (" ;
  } else {
    inhalt += "<i>nicht aktiviert</i>";
  }
  inhalt += "</td></tr>";

  inhalt += "<tr><td>Web API</td><td>";
  if (cfg.data_webapi_check == 1) {
    inhalt += "<span style='color:#008700'>aktiviert</span>"; // (" ;
  } else {
    inhalt += "<i>nicht aktiviert</i>";
  }
  inhalt += "</td></tr>";

  inhalt += "<tr><td>MQTT</td><td>";
  if (cfg.data_mqtt_check == 1) {
    inhalt += "<span style='color:#008700'>aktiviert</span>"; // (" ;
  } else {
    inhalt += "<i>nicht aktiviert</i>";
  }
  inhalt += "</td></tr>";

  inhalt += "<tr><td>OverTheAir Update</td><td>";
  if (cfg.data_ota_check == 1) {
    inhalt += "<span style='color:#008700'>aktiviert</span>"; // (" ;
    //inhalt += ota_zeit;
    //inhalt += "s)" ;
  } else {
    inhalt += "<i>nicht aktiviert</i>";
  }
  inhalt += "</td></tr>";
  inhalt += "</table>";
  inhalt += "</details>";

  inhalt += "<br>";

  inhalt += "<details>";
  inhalt += "<summary style='background-color:#2e86c1;color:#ffffff;padding:5px;'>Sonstiges</summary>";
  inhalt += "<table style='font-size:14px;'>";
  inhalt += "<tr><td><a href=\"/cfg\"><button style=\"background-color: #F7D358; padding: 8px 24px; color: black; border: none; font-size: 14px; border-radius: 4px; width: 150px;\">Konfiguration</button></a></td></tr>";
  inhalt += "<tr><td><br><br><br></td></tr>";
  inhalt += "<tr><td><a href=\"/boot\"><button style=\"background-color: #fa0000; padding: 8px 24px; color: white; border: none; font-size: 14px; border-radius: 4px; width: 150px;\">Sensor restarten</button></a></td></tr>";
  inhalt += "</table>";
  inhalt += "</details>";

  inhalt += "</div>";

  inhalt += "</body>";
  inhalt += "</html>";

  server.send(200, "text/html", inhalt);
}


//********************************************************
void webHandleConfig() {
  String inhalt;

  inhalt  = "<!DOCTYPE html>";
  inhalt += "<html><head><meta name='viewport' content='width=device-width, initial-scale=1.0'><title>" + anwendungsname + "</title></head><body style='font-family:verdana;background-color:#B9DFF8;color:#000000;margin:0px;font-size:11px;'>";
  inhalt += "<p style='font-size:24px;font-weight:bold;background-color:#FFFFFF;color:#000000;padding:30px;padding-left:10px;margin:0px;'>" + anwendungsname + " <span style='font-size:12px;font-weight:normal;'>v" + fw_version + "</span></p>";
  inhalt += "<p style='font-size:18px;font-weight:bold;background-color:#85C5EE;padding-left:10px;padding-top:10px;padding-bottom:10px;margin:0px;'>Konfiguration</p>";

  inhalt += "<div style='padding-left:10px;padding-right:10px;'>";
  if (stationList == "") {
    inhalt += "<br>";
    inhalt += "<a href=\"/\"><button style=\"background-color: #F7D358; padding: 10px 26px; color: black; border: none; font-size: 16px; border-radius: 4px;\">zur&uuml;ck zur Startseite</button></a>";
    inhalt += "<br>";
  }

  inhalt += "<form method='get' action='save' enctype='multipart/form-data'>";
  inhalt += "<table>";

  //**********
  //WLAN
  //**********
  inhalt += "<tr><td colspan=2 style='color:#ffffff;background-color:#2e86c1;padding:5px;'>WLAN</td></tr>";
  if (stationList != "") {
    inhalt += "<tr><td colspan=2>Folgende WLAN-Netze wurden gefunden:</td></tr>";
    inhalt += "<tr>";
    inhalt += stationList;
    inhalt += "<br><br></tr>";
  }
  inhalt += "<tr><td>SSID</td><td><input type='text' size=25 maxlength=30 name='SSID' value='";
  if (stationList == "") {
    inhalt += cfg.SSID;
  }
  inhalt += "'></td></tr>";
  inhalt += "<tr><td>Passwort (<i>max. 63 Zeichen</i>)</td><td><input type='text' size=35 maxlength=63 name='password' value='";
  if (stationList == "") {
    inhalt += cfg.password;
  }
  inhalt += "'></td></tr>";
  inhalt += "<tr><td>Dauer Access Point-Modus</td><td><input type='text' size=5 maxlength=4 name='dauer_ap_form' disabled value='";
  //if (stationList == "") { inhalt += cfg.data_dauer_ap; }
  inhalt += "'> Sekunden <span style='font-size:12px;'>(z.Zt. noch deaktiviert)</span></td></tr>";
  inhalt += "<tr><td><br></td><td><br></td></tr>";

  if (stationList == "") {

    //**********
    //Eigene API
    //**********
    inhalt += "<tr><td colspan=2 style='color:#ffffff;background-color:#2e86c1;padding:5px;'><input type='checkbox' name='eigenapi_check_form' ";
    if (cfg.data_eigenapi_check == 1) {
      inhalt += " checked ";
    }
    inhalt += ">Daten an eigene API senden (POST)</td></tr>";
    inhalt += "<tr><td colspan=2 style='font-size:12px;color:#084B8A;'>Hier k&ouml;nnen die Impulse an eine eigene API &uuml;bergeben werden. Dabei wird eine konfigurierbare URL aufgerufen.<br>Beispiel: &lt;server&gt;:&lt;port&gt;/&lt;pfad&gt;</td></tr>";
    inhalt += "<tr><td>Server</td><td><input type='text' size=25 maxlength=30 name='eigenapi_server_form' value='";
    if (stationList == "") {
      inhalt += cfg.data_eigenapi_server;
    }
    inhalt += "'></td></tr>";
    inhalt += "<tr><td>Pfad</td><td><input type='text' size=35 maxlength=50 name='eigenapi_pfad_form' value='";
    if (stationList == "") {
      inhalt += cfg.data_eigenapi_pfad;
    }
    inhalt += "'></td></tr>";
    inhalt += "<tr><td>Port</td><td><input type='text' size=4 maxlength=5 name='eigenapi_port_form' value='";
    if (stationList == "") {
      inhalt += cfg.data_eigenapi_port;
    }
    inhalt += "'></td></tr>";
    inhalt += "<tr><td>Intervall</td><td><i>bei Impuls</i></td></tr>";
    inhalt += "<tr><td><br></td><td><br></td></tr>";

    //*********
    //Web API
    //*********
    inhalt += "<tr><td colspan=2 style='color:#ffffff;background-color:#2e86c1;padding:5px;'><input type='checkbox' name='webapi_check_form' ";
    if (cfg.data_webapi_check == 1) {
      inhalt += " checked ";
    }
    inhalt += ">bubux.de Web-API nutzen</td></tr>";
    inhalt += "<tr><td colspan=2 style='font-size:12px;color:#084B8A;'>Mit der WebAPI werden die Daten (Impuls, MAC-Adresse, lokale IP und Firmware-Version) an www.bubux.de gesendet wo eine graphische Auswertung des Gasverbrauchs aufbereitet wird. Auf diese Auswertung kann &uuml;ber einen Link in der Web-Oberfl&auml;che des jeweiligen Sensors zugegriffen werden.</td></tr>";
    inhalt += "<tr><td><br></td><td><br></td></tr>";

    //**********
    //MQTT
    //**********
    inhalt += "<tr><td colspan=2 style='color:#ffffff;background-color:#2e86c1;padding:5px;'><input type='checkbox' name='mqtt_check_form' ";
    if (cfg.data_mqtt_check == 1) {
      inhalt += " checked ";
    }
    inhalt += ">Daten an MQTT-Broker senden</td></tr>";
    inhalt += "<tr><td>Server</td><td><input type='text' size=25 maxlength=30 name='mqtt_server_form' placeholder='IP oder URL des MQTT-Servers' value='";
    if (stationList == "") {
      inhalt += cfg.data_mqtt_server;
    }
    inhalt += "'></td></tr>";
    inhalt += "<tr><td>Port</td><td><input type='text' size=4 maxlength=5 name='mqtt_port_form' value='";
    if (stationList == "") {
      inhalt += cfg.data_mqtt_port;
    }
    inhalt += "'> wenn leer bzw. '0' wird der MQTT-Standardport 1883 genutzt</td></tr>";
    inhalt += "<tr><td>Benutzer</td><td><input type='text' size=35 maxlength=50 name='mqtt_benutzer_form' placeholder='Benutzername' value='";
    if (stationList == "") {
      inhalt += cfg.data_mqtt_benutzer;
    }
    inhalt += "'></td></tr>";
    inhalt += "<tr><td>Passwort</td><td><input type='text' size=35 maxlength=50 name='mqtt_passwort_form' placeholder='Passwort' value='";
    if (stationList == "") {
      inhalt += cfg.data_mqtt_passwort;
    }
    inhalt += "'></td></tr>";
    inhalt += "<tr><td>Topic <i>Impuls</i></td><td><input type='text' size=35 maxlength=50 name='mqtt_impuls_topic_form' placeholder='z.B. hausautomation/heizung/impuls' value='";
    if (stationList == "") {
      inhalt += cfg.data_mqtt_impuls_topic;
    }
    inhalt += "'></td></tr>";
    inhalt += "<tr><td>Topic <i>Zaehlerstand</i></td><td><input type='text' size=35 maxlength=50 name='mqtt_zaehlerstand_topic_form' placeholder='z.B. hausautomation/heizung/zaehlerstand' value='";
    if (stationList == "") {
      inhalt += cfg.data_mqtt_zaehlerstand_topic;
    }
    inhalt += "'></td></tr>";
    inhalt += "<tr><td>Intervall</td><td><i>bei Impuls</i></td></tr>";
    inhalt += "<tr><td><br></td><td><br></td></tr>";
    
    //*********
    //Hinweis zum JSON
    //*********
    inhalt += "<tr><td colspan=2 style='color:#ffffff;background-color:#2e86c1;padding:5px;'>Daten per JSON abfragen</td></tr>";
    inhalt += "<tr><td colspan=2 style='font-size:12px;color:#084B8A;'>Mit /json hinter die URL des Sensor, k&ouml;nnen die Messwerte per JSON abgefragt werden <a href='/json' target='_BLANK'>" + ipAdresse + "/json</a>.</td></tr>";
    inhalt += "<tr><td><br></td><td><br></td></tr>";


    //*********
    //OTA
    //*********
    inhalt += "<tr><td colspan=2 style='color:#ffffff;background-color:#2e86c1;padding:5px;'><input type='checkbox' name='ota_check_form' ";
    if (cfg.data_ota_check == 1) {
      inhalt += " checked ";
    }
    inhalt += ">OverTheAir Update aktivieren</td></tr>";
    inhalt += "<tr><td colspan=2 style='font-size:12px;color:#084B8A;'>Mit der Aktivierung von OTA pr&uuml;ft der Sensor in regelm&auml;&szlig;igen Abst&auml;nden ob eine neue Firmwareversion verf&uuml;gbar ist und installiert diese.<br>Aktuell geschieht die Bereitstellung neuer Updates nur auf Anfrage mit Angabe der MAC-Adresse.</td></tr>";
    inhalt += "<tr><td><br></td><td><br></td></tr>";

    //**********
    //Sensor
    //**********
    inhalt += "<tr><td colspan=2 style='color:#ffffff;background-color:#2e86c1;padding:5px;'>Sensordaten</td></tr>";

    inhalt += "<tr><td>Sensorname</td><td><input type='text' size=20 width=60 maxlength=30 name='sensorname_form' value='";
    if (stationList == "") {
      inhalt += cfg.data_sensorname;
    }
    inhalt += "'></td></tr>";

    inhalt += "<tr><td>Impulsgeber</td><td><select name='impulsgeber_form'><option value=0 ";
    if (stationList == "" && cfg.data_impulsgeber == 0) {
      inhalt += " selected";
    }
    inhalt += ">0.1</option><option value=1 ";
    if (stationList == "" && cfg.data_impulsgeber == 1) {
      inhalt += " selected";
    }
    inhalt += ">0.01</option></select>";
    inhalt += " m<sup>3</sup> je Impuls</td></tr>";

    inhalt += "<tr><td>Startwert</td><td><input type='text' size=10 width=60 maxlength=10 name='startwert_form' value='";
    if (stationList == "") {
      inhalt += cfg.data_startwert/100;
    }
    inhalt += "'> m<sup>3</sup> (mit zwei Nachkommastellen z.B. 34023.12)</td></tr>";
    
    inhalt += "<tr><td>Brennwert</td><td><input type='text' size=6 width=60 maxlength=5 name='brennwert_form' value='";
    if (stationList == "") {
      inhalt += cfg.data_brennwert/100;
    }
    inhalt += "'> kWh/m<sup>3</sup></td></tr>";

    inhalt += "<tr><td>Zustandszahl</td><td><input type='text' size=6 width=60 maxlength=4 name='zustandszahl_form' value='";
    if (stationList == "") {
      inhalt += cfg.data_zustandszahl/100;
    }
    inhalt += "'></td></tr>";
    inhalt += "<tr><td></td><td>Brennwert und Zustandszahl k&ouml;nnen der aktuellen Gasrechnung entnommen werden</td></tr>";
    inhalt += "<tr><td>Impulsz&auml;hler</td><td><input type='text' size=6 width=60 maxlength=4 name='impulszaehler_form' value='";
    if (stationList == "") {
      inhalt += cfg.data_impulszaehler;
    }
    inhalt += "'></td></tr>";
    inhalt += "<tr><td></td><td>Der Impulsz&auml;hler wird bei Impuls automatisch hochgez&auml;hlt und gespeichert. Hier kann dieser Wert ge&auml;ndert werden. <br>Die in diesem Bereich eingestellten Werte werden erst nach Neustart des Sensors aktiv.</td></tr>";

    //**********
    //NTP
    //**********
    // Aktuell noch deakiviert
    //inhalt += "<tr><td colspan=2 style='color:#ffffff;background-color:#2e86c1;padding:5px;'>NTP</td></tr>";
    //inhalt += "<tr><td>Zeitserver</td><td><input type='text' size=25 maxlength=50 name='ntp_server_form' disabled value=''";
    //if (stationList == "") { inhalt += cfg.data_ntp_server; }
    //inhalt += "'> wenn leer wird 'pool.ntp.org' genutzt <span style='font-size:12px;'>(Konfiguration z.Zt. noch deaktiviert)</span></td></tr>";
    //inhalt += "<tr><td><br></td><td><br></td></tr>";


  }

  inhalt += "<tr><br><td colspan=2><input type=\"submit\" style=\"background-color: #4CAF50; padding: 10px 26px; color: white; border: none; font-size: 16px; border-radius: 4px;\" value=\"Konfiguration speichern\"></td></tr>";
  inhalt += "</table>";
  inhalt += "</div>";
  inhalt += "</form>";
  inhalt += "</body>";
  inhalt += "</html>";
  inhalt += "\r\n\r\n";
  server.send(200, "text/html", inhalt);
}

//********************************************************
void webHandleConfigSave() {
  String inhalt;

  inhalt  = "<!DOCTYPE html>";
  inhalt += "<html>";
  inhalt += "<html><head><meta name='viewport' content='width=device-width, initial-scale=1.0'><title>" + anwendungsname + "</title></head><body style='font-family:verdana;background-color:#B9DFF8;color:#000000;margin:0px'>";
  inhalt += "<p style='font-size:24px;font-weight:bold;background-color:#FFFFFF;color:#000000;padding:30px;padding-left:10px;margin:0px;'>" + anwendungsname + "</p>";
  inhalt += "<p style='font-size:18px;font-weight:bold;background-color:#85C5EE;padding-left:10px;padding-top:10px;padding-bottom:10px;margin:0px;'>Einstellungen gespeichert</p>";
  inhalt += "<br>";
  inhalt += "<div style='padding-left:10px'>";
  inhalt += "<a href=\"/\"><button style=\"background-color: #F7D358; padding: 10px 26px; color: black; border: none; font-size: 16px; border-radius: 4px;\">zur&uuml;ck zur Startseite</button></a>";
  inhalt += "<br>";
  inhalt += "<p>Die Konfiguration wurde erfolgreich gespeichert<br><br><b>Bei &Auml;nderungen an der WLAN-Konfiguration muss der ESP resetet oder vom Strom getrennt werden!</b></p>";
  inhalt += "</div>";
  inhalt += "</body>";
  inhalt += "</html>";
  inhalt += "\r\n\r\n";
  server.send(200, "text/html", inhalt);

  // ToDo: Weblink unterschiedlich bei AP und STA

  eraseConfig();

  cfg.valid = 1;

  //************************************************************
  //Sensordaten
  //************************************************************
  if (server.hasArg("startwert_form")) {
    float startwert100 = server.arg("startwert_form").toFloat() * 100;
    Serial.println(startwert100);
    Serial.println(cfg.data_startwert);
    if (startwert100!=cfg.data_startwert) {
      verbrauch=startwert100;
      verbrauch_kwh=0;
      Serial.println("Setze Verbrauch");
    }
    cfg.data_startwert = startwert100;
  }
  if (server.hasArg("brennwert_form")) {
    int brennwert100 = server.arg("brennwert_form").toFloat() * 100;
    cfg.data_brennwert = brennwert100;
  }
  if (server.hasArg("zustandszahl_form")) {
    int zustandszahl100 = server.arg("zustandszahl_form").toFloat() * 100;
    cfg.data_zustandszahl = zustandszahl100;
  }
  if (server.hasArg("impulszaehler_form")) {
    int impulszaehler = server.arg("impulszaehler_form").toFloat();
    cfg.data_impulszaehler = impulszaehler;
  }
  if (server.hasArg("impulsgeber_form")) {
    int impulsgeber = server.arg("impulsgeber_form").toFloat();
    cfg.data_impulsgeber = impulsgeber;
    Serial.println(impulsgeber);
  }

  

  //************************************************************
  //WLAN
  //************************************************************
  if (server.hasArg("SSID")) {
    String SSID;
    SSID = server.arg("SSID");
    SSID.replace("%2F", "/");
    SSID.toCharArray(cfg.SSID, (sizeof(cfg.SSID) - 1) );
  }
  if (server.hasArg("password")) {
    String password;
    password = server.arg("password");
    password.replace("%2F", "/");
    password.toCharArray(cfg.password, (sizeof(cfg.password) - 1) );
  }

  //************************************************************
  //Eigene API
  //************************************************************
  if (server.hasArg("eigenapi_check_form")) {
    //Serial.print(cfg.data_eigenapi_check);
    if (server.arg("eigenapi_check_form") == "on") {
      cfg.data_eigenapi_check = 1;
    } else {
      cfg.data_eigenapi_check = 0;
    }
  } else {
    cfg.data_eigenapi_check = 0;
  }
  if (server.hasArg("eigenapi_server_form")) {
    String ea_server;
    ea_server = server.arg("eigenapi_server_form");
    ea_server.replace("%2F", "/");
    ea_server.toCharArray(cfg.data_eigenapi_server, (sizeof(cfg.data_eigenapi_server) - 1) );
  }
  if (server.hasArg("eigenapi_pfad_form")) {
    String ea_pfad;
    ea_pfad = server.arg("eigenapi_pfad_form");
    ea_pfad.replace("%2F", "/");
    ea_pfad.toCharArray(cfg.data_eigenapi_pfad, (sizeof(cfg.data_eigenapi_pfad) - 1) );
  }
  if (server.hasArg("eigenapi_port_form")) {
    cfg.data_eigenapi_port = server.arg("eigenapi_port_form").toInt();
  }
  
  //************************************************************
  //Web API
  //************************************************************
  if (server.hasArg("webapi_check_form")) {
    //Serial.print(cfg.data_webapi_check);
    if (server.arg("webapi_check_form") == "on") {
      cfg.data_webapi_check = 1;
    } else {
      cfg.data_webapi_check = 0;
    }
  } else {
    cfg.data_webapi_check = 0;
  }

  //OTA
  if (server.hasArg("ota_check_form")) {
    if (server.arg("ota_check_form") == "on") {
      cfg.data_ota_check = 1;
    } else {
      cfg.data_ota_check = 0;
    }
  } else {
    cfg.data_ota_check = 0;
  }


  //************************************************************
  //MQTT
  //************************************************************
  if (server.hasArg("mqtt_check_form")) {
    if (server.arg("mqtt_check_form") == "on") {
      cfg.data_mqtt_check = 1;
    } else {
      cfg.data_mqtt_check = 0;
    }
  } else {
    cfg.data_mqtt_check = 0;
  }
  if (server.hasArg("mqtt_server_form")) {
    String mqtt_server;
    mqtt_server = server.arg("mqtt_server_form");
    mqtt_server.replace("%2F", "/");
    mqtt_server.toCharArray(cfg.data_mqtt_server, (sizeof(cfg.data_mqtt_server) - 1) );
  }
  if (server.hasArg("mqtt_port_form")) {
    cfg.data_mqtt_port = server.arg("mqtt_port_form").toInt();
  }
  if (server.hasArg("mqtt_benutzer_form")) {
    String mqtt_benutzer;
    mqtt_benutzer = server.arg("mqtt_benutzer_form");
    mqtt_benutzer.replace("%2F", "/");
    mqtt_benutzer.toCharArray(cfg.data_mqtt_benutzer, (sizeof(cfg.data_mqtt_benutzer) - 1) );
  }
  if (server.hasArg("mqtt_passwort_form")) {
    String mqtt_passwort;
    mqtt_passwort = server.arg("mqtt_passwort_form");
    mqtt_passwort.replace("%2F", "/");
    mqtt_passwort.toCharArray(cfg.data_mqtt_passwort, (sizeof(cfg.data_mqtt_passwort) - 1) );
  }
  if (server.hasArg("mqtt_impuls_topic_form")) {
    String mqtt_impuls_topic;
    mqtt_impuls_topic = server.arg("mqtt_impuls_topic_form");
    mqtt_impuls_topic.replace("%2F", "/");
    mqtt_impuls_topic.toCharArray(cfg.data_mqtt_impuls_topic, (sizeof(cfg.data_mqtt_impuls_topic) - 1) );
  }
  if (server.hasArg("mqtt_zaehlerstand_topic_form")) {
    String mqtt_zaehlerstand_topic;
    mqtt_zaehlerstand_topic = server.arg("mqtt_zaehlerstand_topic_form");
    mqtt_zaehlerstand_topic.replace("%2F", "/");
    mqtt_zaehlerstand_topic.toCharArray(cfg.data_mqtt_zaehlerstand_topic, (sizeof(cfg.data_mqtt_zaehlerstand_topic) - 1) );
  } 

  if (server.hasArg("sensorname_form")) {
    String sensorname;
    sensorname = server.arg("sensorname_form");
    sensorname.replace("%2F", "/");
    sensorname.toCharArray(cfg.data_sensorname, (sizeof(cfg.data_sensorname) - 1) );
  }
  
  //************************************************************
  // NTP
  //************************************************************
  if (server.hasArg("ntp_server_form")) {
    String ntp_server;
    ntp_server = server.arg("ntp_server_form");
    ntp_server.replace("%2F", "/");
    ntp_server.toCharArray(cfg.data_ntp_server, (sizeof(cfg.data_ntp_server) - 1) );
  }

  Serial.println("Speichere Konfiguration in EEPROM...");
  speicherekonfig();
  Serial.println("...fertig!");
  //system_restart();
}

//********************************************************
void webHandleJSON() {
  String inhalt;

  inhalt = "{\"Sensor\":\"";
  inhalt += anwendungsname;
  inhalt += "\",\"IP\":\"";
  inhalt += ipAdresse;
  inhalt += "\"";

  inhalt += ",\"Startwert\":\"";
  inhalt += startwert/100;
  inhalt += "\"";

  inhalt += ",\"Impulse\":\"";
  inhalt += cfg.data_impulszaehler;
  inhalt += "\"";

  inhalt += ",\"Zaehlerstand\":\"";
  inhalt += verbrauch/100;
  inhalt += "\"";

  inhalt += "}";

  server.send(200, "application/json", inhalt);
}


//********************************************************
void webHandleBoot() {
  String inhalt;
  inhalt  = "<!DOCTYPE html>";
  inhalt += "<html><head><meta name='viewport' content='width=device-width, initial-scale=1.0'></head><title>" + anwendungsname + "</title><body style='font-family:verdana;background-color:#B9DFF8;color:#000000;margin:0px'>";
  inhalt += "<p style='font-size:24px;font-weight:bold;background-color:#FFFFFF;color:#000000;padding:30px;padding-left:10px;margin:0px;'>" + anwendungsname + " <span style='font-size:12px;font-weight:normal;'>v" + fw_version + "</span></p>";
  inhalt += "<p style='font-size:18px;font-weight:bold;background-color:#85C5EE;padding-left:10px;padding-top:10px;padding-bottom:10px;margin:0px;'>Reboot des Sensors</p>";
  inhalt += "<br>";
  inhalt += "<div style='padding-left:10px;padding_right:10px;'>";
  inhalt += "<p>Der Sensor wird <b>jetzt</b> rebootet</p>";
  inhalt += "<p>Bitte in ca. 20 Sekunden <a href=\"/\">hier</a> klicken</p>";
  inhalt += "</body>";
  inhalt += "</html>";
  inhalt += "\r\n\r\n";
  server.send(200, "text/html", inhalt);
  system_restart();
}
