#include <stdio.h>
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
HumiditySensor::~HumiditySensor() { this->data.value = ""; };

/**
 * @brief get float value of ambient humidity of the submarine (~10 %)
 * @return const SensorData& 
 */
const SensorData& HumiditySensor::getData() {
  this->value = 10 + ((float)(this->aleaGenVal() % 5) / 10) + ((float)(this->aleaGenVal() % 5) / 100);
  this->data.value = to_string(this->value);

  return this->data;
}