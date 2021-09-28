/**
 * @author @Juknum (Julien CONSTANT)
 * @file Sensor.cpp
 * @date 27/09/2021
 * @brief Sensor class header file
 */

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
 * @brief Construct a new Sensor Base:: Sensor Base object from another sensor
 * @param sB sensor base
 */
SensorBase::SensorBase(const SensorBase& sB) {
  this->data.sensorType = sB.data.sensorType;
  this->data.dataType = sB.data.dataType;
  this->data.value = sB.data.value;
};

/**
 * @brief supercharge equal operator to assign existing values of a sensor to targeted sensor
 * @param sB sensor base
 * @return SensorBase& target
 */
SensorBase& SensorBase::operator=(const SensorBase& sB) {
  this->data.sensorType = sB.data.sensorType;
  this->data.dataType = sB.data.dataType;
  this->data.value = sB.data.value;
  return *this;
};

/**
 * @brief Destroy the Sensor Base:: Sensor Base object
 */
SensorBase::~SensorBase() {
  this->data.value = "";
};

/**
 * @brief Randomly generate an integer
 * @return int 
 */
int SensorBase::aleaGenVal() {
  return rand();
}