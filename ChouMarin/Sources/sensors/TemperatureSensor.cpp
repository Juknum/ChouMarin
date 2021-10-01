/**
 * @author @Juknum (Julien CONSTANT)
 * @file Light.cpp
 * @date 30/09/2021
 * @brief Temperature sensor class main file
 */

#include <stdio.h>
#include "./headers/TemperatureSensor.hpp"
#include "../../Includes/constants.hpp"

using namespace std;

/**
 * @brief Construct a new Humidity Sensor:: Humidity Sensor object
 */
TemperatureSensor::TemperatureSensor() : Sensor <float> (e_temperature, e_float) {};

/**
 * @brief Destroy the Humidity Sensor:: Humidity Sensor object
 */
TemperatureSensor::~TemperatureSensor() {};

/**
 * @brief get float value of ambient temperature of the submarine (~21 C°)
 * @return const SensorData& 
 */
const SensorData &TemperatureSensor::getData() {
  this->value = this->aleaGenVal<float>(20, 22, 1);
  this->data.value = to_string(this->value);

  return this->data;
}