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
// less than MIN_TEMP will force new data readout (sensor sometime report -17°C along with 0ppm)
#define CO2_MIN_PPM 350
#define CO2_MIN_TEMP 0

#endif //HARDWARE_CONFIG_H