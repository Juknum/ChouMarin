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

template <typename T> T SensorBase::aleaGenVal(T min, T max) {
  return (T) 5;
};

template <typename T> T SensorBase::aleaGenVal(T min, T max, int precision) {
  return (T) precision;
}

// int power = 1;

// if (precision != 0)
//   for (int i = 0; i < precision; i++)
//     power *= 10;

// if (precision == 0)
//   return (T)min + (max == NULL ? rand() : rand() % ((int)max - (int)min))

// return min + (max == NULL) ? rand() + ((precision != 0) ? (float)(aleaGenVal(0, power, 0) / (float)power) : (int)0) : (rand() + (precision != 0) ? (float)(aleaGenVal(0, power, 0) / (float)power) : (int)0) % (max - min);

// /**
//  * @brief Randomly generate an integer within range (max & min)
//  * @param min minimum range
//  * @param max maximum range
//  * @return int random number between min & max
//  */
// int SensorBase::aleaGenVal(int min = 0, int max = NULL) {
//   return min + (max == NULL) ? rand() : rand()%(max - min);
// }

// /**
//  * @brief Randomly generate an integer
//  * @return int 
//  */
// int SensorBase::aleaGenVal() {
//   return rand();
// }

// /**
//  * @brief Randomly generate a float with precision within the decimal value
//  * @param precision number of decimals
//  * @return float
//  */
// float SensorBase::aleaGenVal(int precision) {
//   int power = 1;
  
//   for (int i = 0; i < precision; i++) {
//     power *= 10;
//   }

//   return aleaGenVal() + (precision > 0) ? (float) (aleaGenVal(0, power) / (float) power) : 0.0;
// }