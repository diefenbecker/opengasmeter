# gas meter measurement
Counts impulses from your gas meter using a ESP8266 with simple rred contact. 

## Supported sensors

- All reed contacts

## Wiring

The reed contact must be connected to D4 and GND

## Latest version already compiled

Find here ![Version 1030](https://github.com/diefenbecker/zisternenmessung/blob/main/opencistern_1030.bin?raw=true) a already compiled version tested with NodeMCU and Wemos D1 mini

## Start-Up

Once the firmware has been flashed to the NodeMCU and everything is correctly wired, the sensor can be commissioned.

The sensor tries to connect to a configured WLAN. If this does not work (which is the case during the first start-up), the sensor creates a WLAN access point with the name "WLAN cistern" which should be found in the smartphone, for example. Connect to this WLAN.

Now call up the address http://192.168.4.1 in the browser of the connected device. This address is usually also displayed and linked in the connection settings of the connected WLAN. The configuration page of the sensor now opens.

Enter the SSID and the password of the home WLAN and click on "Save configuration". The other settings (cistern form, etc.) can be made later.

The sensor then restarts and attempts to connect to the home WLAN. If this was successful, the access point is no longer accessible and the sensor should have been assigned an IP address in the network. This can be looked up in the router (e.g. in the Friztbox under "Home network -> Network").

If the "WLAN cistern" access point is still visible, the connection to the home WLAN was not successful. Then carry out the above steps again.


## More information

More information about installation etc. can be found on [http://blog.bubux.de/fuellstandmessung-der-zisterne-mittels-esp8266-nodemcu-und-ultraschallsensor/](http://blog.bubux.de/gasverbrauch-mit-esp8266-messen/). There are several articles that deal with the topic.


## Use own api

The measured data can be sent to your own interface via http post. A configurable URL is called and the values for the distance and the level in the variables are _abstand and _fuellstand transferred. Example: http://server:port/path_to_own_api?abs=_abstand&hoehe=_fuellstand

## Use bubux api

With the WebAPI, the data (impuls, MAC address, local IP and firmware version) is sent to www.bubux.de where a graphical evaluation of the gas consumption is prepared. This evaluation can be accessed via a link in the web interface of the respective sensor. No central home automation is necessary here.

![Statistik](https://github.com/diefenbecker/opengasmeter/screenshots/gas_auswertung.PNG)

## JSON
  
With /json behind the URL of the sensor, the measured values can be queried via JSON. For example, 192.168.178.49/json.

![JSON example](https://github.com/diefenbecker/zisternenmessung/blob/main/screenshots/json.PNG?raw=true)
  
## Use MQTT

Send the measured data to an MQTT broker

![MQTT Konfig](https://github.com/diefenbecker/screenshots/gas_mqtt.PNG)


## Switchable output

The software supports a switchable output to D4 depending on a configurable minimum and maximum level

![Relausausgang](https://github.com/diefenbecker/opengasmeter/zisternenmessung/blob/main/screenshots/relais.PNG?raw=true)

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
- Pushover.h (https://github.com/ArduinoHannover/Pushover)
- myTypes.h

## Donation

To support this project, feel free to make a small donation. The donations go to the foundation "Bärenherz" in Wiesbaden (https://www.baerenherz.de/de/)

[![](https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif)](https://www.paypal.com/donate/?hosted_button_id=2GUA7DMLQRAUY)

## Installation

Since the installation is individual depending on the cistern, I won't say much about it. I will only say that I packed the sensor into a surface-mounted box from the DIY store and "potted" it with hot glue. Resin would probably have been better, but the sensor works perfectly so far. The sensor hangs downwards on a board in the cistern. The NodeMCU is connected to a cable about 6m long and is housed in a small storage room.

![Einbau1](https://github.com/diefenbecker/zisternenmessung/blob/main/screenshots/einbau1.PNG?raw=true)
![Einbau2](https://github.com/diefenbecker/zisternenmessung/blob/main/screenshots/einbau2.PNG?raw=true)
![EInbau3](https://github.com/diefenbecker/zisternenmessung/blob/main/screenshots/einbau3.PNG?raw=true)

## Some screenshots of the webinterface with it´s configuration page

![Startpage](https://github.com/diefenbecker/zisternenmessung/blob/main/screenshots/startseite.PNG?raw=true)

![Configuration page (1)](https://github.com/diefenbecker/zisternenmessung/blob/main/screenshots/konfig1.PNG?raw=true)

![Configuration page (2)](https://github.com/diefenbecker/zisternenmessung/blob/main/screenshots/konfig2.PNG?raw=true)

![Configuration page (3)](https://github.com/diefenbecker/zisternenmessung/blob/main/screenshots/konfig3.PNG?raw=true)
