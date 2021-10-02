/**
 * @author @Juknum (Julien CONSTANT)
 * @file Light.cpp
 * @date 30/09/2021
 * @brief Temperature sensor class main file, herited from Sensor class
 */

#include <stdio.h>
#include "../../Includes/sensors/TemperatureSensor.hpp"
#include "../../Includes/constants.hpp"

/**
 * @brief Construct a new Humidity Sensor:: Humidity Sensor object
 */
TemperatureSensor::TemperatureSensor() : Sensor<float>(e_temperature, e_float){};

/**
 * @brief Destroy the Humidity Sensor:: Humidity Sensor object
 */
TemperatureSensor::~TemperatureSensor(){};

/**
 * @brief get float value of ambient temperature of the submarine (~21.25 C°)
 * @return const SensorData& 
 */
const SensorData& TemperatureSensor::getData()
{
	this->m_value = this->aleaGenVal<float>(21.01, 21.73);
	this->m_data.value = std::to_string(this->m_value);

	return this->m_data;
}