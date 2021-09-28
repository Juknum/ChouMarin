#include <string.h>
#include "headers/LightSensor.hpp"
#include "../../Includes/constants.hpp"

/**
 * @brief Construct a new Light Sensor:: Light Sensor object
 */
LightSensor::LightSensor(): Sensor<bool>(e_light, e_bool) {};

/**
 * @brief Destroy the Light Sensor:: Light Sensor object
 */
LightSensor::~LightSensor() { this->data.value = ""; };

/**
 * @brief get boolean value of the light sensor (true = light on | false = light off)
 * @return const SensorData& 
 */
const SensorData& LightSensor::getData() {
  this->value = this->aleaGenVal() % 2;
  this->data.value = (this->value == 0) ? "false" : "true";

  return this->data;
}