/*
*   ESP8266 MQTT CO2 Sensor
*   Hardware / Board specific Settings
*/
#ifndef HARDWARE_CONFIG_H
#define HARDWARE_CONFIG_H

#include <Arduino.h>
#include <ESP8266WiFi.h>

#ifdef D1_MINI
#define LED D4
// LED is inverted on D1 Mini
#define LEDON LOW
#define LEDOFF HIGH
#endif

// Software Serial for CO2 sensor
#define RX_PIN D5
#define TX_PIN D6
#define SSRATE 9600

// Plausible minimum ppms for CO2 readouts
#define CO2_MIN_PPM 350

#endif //HARDWARE_CONFIG_H