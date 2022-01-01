/*
 * ESP8266 MQTT CO2 Sensor
 * WiFi specific setup
 */
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "wifi-config.h"

// Define Variables
const char *ssid = WIFI_SSID;
const char *password = WIFI_PSK;
