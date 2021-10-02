/**
 * @author @Juknum (Julien CONSTANT)
 * @file LightSensor.cpp
 * @date 27/09/2021
 * @brief Light sensor class main file, herited from Sensor class
 */

#include "../../Includes/sensors/LightSensor.hpp"
#include "../../Includes/constants.hpp"

/**
 * @brief Construct a new Light Sensor:: Light Sensor object
 */
LightSensor::LightSensor() : Sensor<bool>(e_light, e_bool){};

/**
 * @brief Destroy the Light Sensor:: Light Sensor object
 */
LightSensor::~LightSensor(){};

/**
 * @brief get boolean value of the light sensor (true = light on | false = light off)
 * @return const SensorData& 
 */
const SensorData& LightSensor::getData()
{
	this->m_value = this->aleaGenVal<int>() % 2;
	this->m_data.value = (this->m_value < 1) ? "false" : "true";

	return this->m_data;
};