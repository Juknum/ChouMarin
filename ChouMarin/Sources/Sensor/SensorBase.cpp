/**
 * @file SensorBase.cpp
 * @author @Juknum - Julien CONSTANT (julien.constant@utbm.fr)
 * @brief Sensor base for all sensors
 * @date 2021-10-04
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

#include "SensorBase.hpp"

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
SensorBase::SensorBase(SensorType sT, DataType dT, short unsigned int id)
{
  this->m_data.sensorType = sT;
  this->m_data.dataType = dT;
  this->m_data.value = "";
  this->m_data.id = id;
};
