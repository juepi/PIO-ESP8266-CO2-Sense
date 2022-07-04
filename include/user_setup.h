/*
 *   ESP8266 Template
 *   Include all config files and Setup Function declarations
 */
#ifndef USER_SETUP_H
#define USER_SETUP_H

// Define required user libraries here
// Don't forget to add them into platformio.ini
#include "MHZ19.h"
#include <SoftwareSerial.h>

// Declare user setup and main loop functions
extern void user_setup();
extern void user_loop();

// Declare global user specific objects
extern MHZ19 CO2sense;
extern SoftwareSerial SoftSer;

// Software Serial for CO2 sensor
#define RX_PIN D5
#define TX_PIN D6
#define SSRATE 9600

// Plausible minimum ppms for CO2 readouts
// less than MIN_TEMP will force new data readout (sensor sometime report -17°C along with 0ppm)
#define CO2_MIN_PPM 350
#define CO2_MIN_TEMP 0

#endif // USER_SETUP_H