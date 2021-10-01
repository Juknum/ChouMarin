/**
 * @author @Juknum (Julien CONSTANT)
 * @file PressureSensor.cpp
 * @date 27/09/2021
 * @brief Pressure sensor class main file
 */

#include "headers/PressureSensor.hpp"
#include "../../Includes/constants.hpp"

using namespace std;

/**
 * @brief Construct a new Pressure Sensor:: Pressure Sensor object
 */
PressureSensor::PressureSensor() : Sensor<int>(e_pressure, e_int){};

/**
 * @brief Destroy the Pressure Sensor:: Pressure Sensor object
 */
PressureSensor::~PressureSensor(){};

/**
 * @brief get integer value of the pressure sensor (~ 1)
 * @return const SensorData& 
 */
const SensorData &PressureSensor::getData() {
  this->value = this->aleaGenVal<int>(1, 1);
  this->data.value = to_string(this->value);

  return this->data;
};