/*
 * ESP8266 Template
 * ==================
 * User specific function "user_loop" called in main loop
 * User specific funtion "user_setup" called in setup loop
 * Add stuff you want to run here
 */
#include "setup.h"

// Setup CO2 Sensor instance
MHZ19 CO2sense;

// Setup Software Serial instance
SoftwareSerial SoftSer(RX_PIN, TX_PIN);

/*
 * User Setup Loop
 * ========================================================================
 */
void user_setup()
{
  // Add stuff you want to initialize in setup here
  // ===============================================
  // Setup SoftwareSerial and CO2 Sensor
  DEBUG_PRINTLN("Setup Software Serial and Sensor..");
  SoftSer.begin(SSRATE);
  CO2sense.begin(SoftSer);
  DEBUG_PRINTLN("Run Auto calibration..");
  CO2sense.autoCalibration();
}

/*
 * User Main Loop
 * ========================================================================
 */
void user_loop()
{
  // Add stuff you want to periodically run in main loop here
  // =========================================================
  int CO2;
  CO2 = CO2sense.getCO2();
  DEBUG_PRINTLN("CO2: " + String(CO2) + " ppm");
  int8_t Temp;
  Temp = CO2sense.getTemperature();
  DEBUG_PRINTLN("Temp: " + String(Temp) + " degC");
  if (Temp < CO2_MIN_TEMP)
  {
    // Implausible temeprature received, redo readout
    MqttDelay(2000);
    CO2 = CO2sense.getCO2();
    Temp = CO2sense.getTemperature();
  }

  if (CO2 < CO2_MIN_PPM)
  {
    // Implausible PPMs, redo readout
    MqttDelay(2000);
    CO2 = CO2sense.getCO2();
    Temp = CO2sense.getTemperature();
  }

  mqttClt.publish(co2_topic, String(CO2).c_str(), true);
  mqttClt.publish(temp_topic, String(Temp).c_str(), true);
  delay(100);

#ifdef ONBOARD_LED
  // Toggle LED at each loop
  ToggleLed(LED, 500, 4);
#endif
  DEBUG_PRINTLN("User Loop finished, sleep for 10 minutes.");
  MqttDelay(600000);
}