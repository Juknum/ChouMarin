/**
 * @file LightSensor.cpp
 * @author @Juknum - Julien CONSTANT (julien.constant@utbm.fr)
 * @brief Light sensor
 * @date 2021-09-27
 * 
 * @copyright MIT License
 * > Copyright (c) 2021 Julien Constant
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * ! THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * ! IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * ! FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * ! AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * ! LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * ! OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * ! SOFTWARE.
 */

#include "LightSensor.hpp"

/**
 * @brief Construct a new Light Sensor:: Light Sensor object
 */
LightSensor::LightSensor(short unsigned int id) : Sensor<bool>(e_light, e_bool, id){};

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
	time_t t = time(0);
	std::string date = ctime(&t);
	date.erase(24, 25); // remove the '\n' at the end
	this->m_data.time = date;

	this->m_value = this->aleaGenVal<int>() % 2;
	this->m_data.value = (this->m_value < 1) ? "false" : "true";
	
	return this->m_data;
};