/**
 * @file TemperatureSensor.cpp
 * @author @Juknum - Julien CONSTANT (julien.constant@utbm.fr)
 * @brief Temperature sensor
 * @date 2021-09-30
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

#include "TemperatureSensor.hpp"

/**
 * @brief Construct a new Humidity Sensor:: Humidity Sensor object
 */
TemperatureSensor::TemperatureSensor(unsigned int id) : Sensor<float>(e_temperature, e_float, id){};

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
	time_t t = time(0);
	std::string date = ctime(&t);
	date.erase(24, 25); // remove the '\n' at the end
	this->m_data.time = date;

	this->m_value = this->aleaGenVal<float>(21.01, 21.73);
	this->m_data.value = std::to_string(this->m_value);

	return this->m_data;
}