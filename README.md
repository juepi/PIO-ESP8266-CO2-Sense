# Introduction 
Sketch to readout CO2 PPMs from Winsen MH-Z19C sensor. Based on [PIO-ESP8266-Template](https://github.com/juepi/PIO-ESP8266-Template).

## Local Requirements
A (local) MQTT broker is mandatory for OTA-Flashing and sending data to MQTT.  

## Wiring the sensor to the ESP
* D5 -> to sensors TX pin
* D6 -> to sensors RX pin
* 5V + GND -> to sensors power pins  
Do note that the MH-Z19 use 3.3V levels for the serial communication, so you can wire them directly to the ESP.

## Generic Requirements
Please see [PIO-ESP8266-Template](https://github.com/juepi/PIO-ESP8266-Template) for general requirements and usage of this sketch.

# Changelog

## Release 1.0.0
- Initial Release

## Release 1.0.3
- Reworked Code based on PIO-ESP8266-Template v1.0.3
