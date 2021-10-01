/**
 * @author @Juknum (Julien CONSTANT)
 * @file HumiditySensor.cpp
 * @date 27/09/2021
 * @brief Humidity sensor class main file
 */

#include "../../Includes/sensors/HumiditySensor.hpp"
#include "../../Includes/constants.hpp"

/**
 * @brief Construct a new Humidity Sensor:: Humidity Sensor object
 */
HumiditySensor::HumiditySensor(): Sensor(e_humidity, e_float) {};

/**
 * @brief Destroy the Humidity Sensor:: Humidity Sensor object
 */
HumiditySensor::~HumiditySensor() {};

/**
 * @brief get float value of ambient humidity of the submarine (~10.5 %)
 * @return const SensorData& 
 */
const SensorData& HumiditySensor::getData() {
  this->value = this->aleaGenVal<float>(9, 12, 2);
  this->data.value = std::to_string(this->value);

  return this->data;
}