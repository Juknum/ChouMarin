/**
 * @author @Juknum (Julien CONSTANT)
 * @file Sensor.cpp
 * @date 27/09/2021
 * @brief Sensor class header file
 */

#include <random>
#include "../Includes/Sensor.hpp"

template <class T> Sensor<T>::Sensor(): T() {};

/**
 * @brief Construct a new Sensor Base:: Sensor Base object
 */
SensorBase::SensorBase() {
  this->data.sensorType = e_unknown_type;
  this->data.dataType = e_unknown_data;
};

/**
 * @brief Construct a new Sensor Base:: Sensor Base object with values
 * @param sT sensor type 
 * @param dT sensor data type
 */
SensorBase::SensorBase(SensorType sT, DataType dT) {
  this->data.sensorType = sT;
  this->data.dataType = dT;
  this->data.value = "";
};

/**
 * @brief Destroy the Sensor Base:: Sensor Base object
 */
SensorBase::~SensorBase() {
  this->data.value = "";
};
