/*
 * ESP8266 MQTT CO2 Sensor
 * Hardware specific setup
 */
#include <Arduino.h>
#include "hardware-config.h"

// Set ADC mode to read VCC (Attn: Pin A0 must be floating!)
// ==========================================================
ADC_MODE(ADC_VCC);
