/**
 * @author @Juknum (Julien CONSTANT)
 * @file Sensor.cpp
 * @date 27/09/2021
 * @brief Sensor class main file, used as "parent" for all sensors
 */

#include <random>
#include "../Includes/Sensor.hpp"

template <class T>
Sensor<T>::Sensor() : T(){};

/**
 * @brief Construct a new Sensor Base:: Sensor Base object with default values
 */
SensorBase::SensorBase()
{
	this->m_data.sensorType = e_unknown_type;
	this->m_data.dataType = e_unknown_data;
};

/**
 * @brief Construct a new Sensor Base:: Sensor Base object with values
 * @param sT sensor type 
 * @param dT sensor data type
 */
SensorBase::SensorBase(SensorType sT, DataType dT)
{
	this->m_data.sensorType = sT;
	this->m_data.dataType = dT;
	this->m_data.value = "";
};
