/**
 * @file Sensor.hpp
 * @author @Juknum - Julien CONSTANT (julien.constant@utbm.fr)
 * @brief Sensor parent file, used for all sensors
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

#ifndef SENSOR_HPP_
#define SENSOR_HPP_

#include "../constants.hpp"
#include "SensorBase.hpp"

// template for all existing sensors
template <class T>
class Sensor : public SensorBase
{
protected:
	T m_value;

public:
	Sensor<T>();
	Sensor<T>(SensorType sT, DataType dT, short unsigned int id) : SensorBase(sT, dT, id), m_value() {};
	virtual ~Sensor() {};

	virtual const SensorData& getData() = 0;
};

#endif // SENSOR_HPP_
