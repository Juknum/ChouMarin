/**
 * @author @Juknum (Julien CONSTANT)
 * @file Scheduler.cpp
 * @date 27/09/2021
 * @brief Scheduler class main file
 */

#include <stdlib.h>
#include <string>
#include <time.h>

#include "Sensors/headers/HumiditySensor.hpp"
#include "Sensors/headers/LightSensor.hpp"
#include "Sensors/headers/TemperatureSensor.hpp"
#include "../Includes/Scheduler.hpp"

/**
 * @brief Construct a new Scheduler:: Scheduler object
 */
Scheduler::Scheduler() {
  // add sensors to the list of sensors
  listSensors.push_back(&this->humiditySensor);
  listSensors.push_back(&this->lightSensor);
  listSensors.push_back(&this->temperatureSensor);

  // add time interval check for sensors
  timeInterval.push_back(TimeInterval(e_humidity, 1000));
  timeInterval.push_back(TimeInterval(e_light, 1000));
  timeInterval.push_back(TimeInterval(e_temperature, 1000));

  // watching
  while (true) {
    for (int i = 0; i < (int) this->timeInterval.size(); ++i) {
      if (timeInterval[i].checkTime()) {
        for (int j = 0; j < (int) listSensors.size(); j++) {
          const SensorData& data = listSensors[j]->getData();

          if (data.sensorType == timeInterval[i].sensorType) {
            server << listSensors[j]->getData();
          }
        }
      }
    }
  }
};

/**
 * @brief Destroy the Scheduler:: Scheduler object
 */
Scheduler::~Scheduler() {}

/**
 * @brief Construct a new Time Interval:: Time Interval object with default values
 */
TimeInterval::TimeInterval(): sensorType(e_unknown_type), tClock(), duration(1000) {};

/**
 * @brief Construct a new Time Interval:: Time Interval object with given values
 * @param sT SensorType 
 * @param ms Duration between checks
 */
TimeInterval::TimeInterval(SensorType sT, int ms): sensorType(sT), tClock(), duration(ms) {};

/**
 * @brief Destroy the Time Interval:: Time Interval object
 */
TimeInterval::~TimeInterval() {};

/**
 * @brief check if the actual time is the time where we need to check the sensor (oof)
 * @return true if this is the time
 * @return false either
 */
bool TimeInterval::checkTime() {
  if ((double)(clock() - this->tClock) * 1000 / CLOCKS_PER_SEC >= this->duration) {
    this->tClock = clock();
    return true;
  }
  
  return false;
}