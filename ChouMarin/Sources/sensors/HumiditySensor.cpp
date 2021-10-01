/**
 * @author @Juknum (Julien CONSTANT)
 * @file HumiditySensor.cpp
 * @date 27/09/2021
 * @brief Humidity sensor class main file
 */

#include "./headers/HumiditySensor.hpp"
#include "../../Includes/constants.hpp"

using namespace std;

/**
 * @brief Construct a new Humidity Sensor:: Humidity Sensor object
 */
HumiditySensor::HumiditySensor(): Sensor(e_humidity, e_float) {};

/**
 * @brief Destroy the Humidity Sensor:: Humidity Sensor object
 */
HumiditySensor::~HumiditySensor() {};

/**
 * @brief get float value of ambient humidity of the submarine (~10 %)
 * @return const SensorData& 
 */
const SensorData& HumiditySensor::getData() {
  this->value = this->aleaGenVal<float>(9, 11, 2);
  this->data.value = to_string(this->value);

  return this->data;
}