# gas meter measurement
Counts pulses from your gas meter using a ESP8266 with a simple reed switch. Supports gas meters with magnet with 0.1 m³ per pulse 0,01 m³ per pulse. The measured pulses are output on a genersted website (without any Homeautomation central), data can be send via MQTT to your own MQTT broker or via HTTP to an own interface. Data is additinolly prepared as JSON message. In addition, it is possible to let prepare the data on www.bubux.de.

## Supported sensors

- All reed switches (normally open). Which reed exactly fit to the used gas meter needs to be figured out
  
## Wiring

The reed contact must be connected to D4 and GND (or changed in the source code)

## Latest version already compiled

Find here ![Version 1030](https://github.com/diefenbecker/zisternenmessung/blob/main/opencistern_1030.bin?raw=true) a already compiled version tested with NodeMCU and Wemos D1 mini

## Start-Up

Once the firmware has been flashed to the NodeMCU and everything is correctly wired, the sensor can be commissioned.

The sensor tries to connect to a configured WLAN. If this does not work (which is the case during the first start-up every time), the sensor creates a WLAN access point with the name "WLAN-Gaszaehler" which should be found in the smartphone, for example. Connect to this WLAN.

Now call up the address http://192.168.4.1 in the browser of the connected device. This address is usually also displayed and linked in the connection settings of the connected WLAN. The configuration page of the sensor now opens.

Enter the SSID and the password of the home WLAN and click on "Save configuration". The other settings (cistern form, etc.) can be made later.

The sensor then restarts and attempts to connect to the home WLAN. If this was successful, the access point is no longer accessible and the sensor should have been assigned an IP address in the network. This can be looked up in the router.

If the "WLAN-gaszaehler" access point is still visible, the connection to the home WLAN was not successful. Then carry out the above steps again.


## More information

More information about installation etc. can be found on [http://blog.bubux.de/gasverbrauch-mit-esp8266-messen/](http://blog.bubux.de/gasverbrauch-mit-esp8266-messen/). There are several articles that deal with the topic.


## Use own api

The measured pulses can be sent to your own interface via http post. A configurable URL is called with every measured pulse.

## Use bubux api

With the WebAPI, the data (impuls, MAC address, local IP and firmware version) is sent to www.bubux.de where a graphical evaluation of the gas consumption is prepared. This evaluation can be accessed via a link in the web interface of the respective sensor. No central home automation is necessary here.

![Statistik](https://github.com/diefenbecker/opengasmeter/blob/main/screenshots/gas_auswertung.PNG)

## JSON
  
With /json behind the URL of the sensor, the measured values can be queried via JSON. For example, 192.168.178.49/json.
This data can easily integrated in Home Assistant (see https://www.home-assistant.io/integrations/rest/) 

![JSON](https://github.com/diefenbecker/opengasmeter/blob/main/screenshots/gaszaehler_screenshot3.PNG)
  
## Use MQTT

Send the measured data to an MQTT broker

![MQTT Konfig](https://github.com/diefenbecker/opengasmeter/blob/main/screenshots/gaszaehler_mqtt.png)


## Used libraries

- ESP8266WiFi.h
- ESP8266mDNS.h
- ESP8266WebServer.h
- ESP8266HTTPClient.h
- ESP8266httpUpdate.h
- Ticker.h
- EEPROM.h
- Wire.h

All libraries listed above are included in the ESP8266 core (https://github.com/esp8266/Arduino) . Currently it is mandatory to use version 2.4.7! This is done e.g. in the Borad-Manager of the Arduino IDE.

- PubSubClient.h (https://pubsubclient.knolleary.net/)
- NTPClient.h (https://github.com/arduino-libraries/NTPClient)
- WiFiUdp.h
- SimpleTimer.h (https://github.com/kiryanenko/SimpleTimer)
- myTypes.h

## Donation

To support this project, feel free to make a small donation. The donations go to the foundation "Bärenherz" in Wiesbaden (https://www.baerenherz.de/de/)

[![](https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif)](https://www.paypal.com/donate/?hosted_button_id=2GUA7DMLQRAUY)

## Installation

The reed switch must be placed in the appropriate at the gas meter

## Some screenshots of the webinterface with it´s configuration page

![Startpage](https://github.com/diefenbecker/opengasmeter/blob/main/screenshots/gaszaehler_screenshot1.PNG?raw=true)

![Configuration page (1)](https://github.com/diefenbecker/opengasmeter/blob/main/screenshots/gaszaehler_screenshot2.PNG?raw=true)
