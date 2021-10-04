/**
 * @file TimeInterval.cpp
 * @author @Juknum - Julien CONSTANT (julien.constant@utbm.fr)
 * @brief Manage time & check time of each sensor
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

#include "TimeInterval.hpp"

/**
 * @brief Construct a new Time Interval:: Time Interval object with default values
 */
TimeInterval::TimeInterval() : m_sensorType(e_unknown_type), m_clock(), m_duration(1000){};

/**
 * @brief Construct a new Time Interval:: Time Interval object with given values
 * @param sT SensorType 
 * @param ms Duration between checks
 */
TimeInterval::TimeInterval(SensorType sT, int ms) : m_sensorType(sT), m_clock(), m_duration(ms){};

/**
 * @brief Destroy the Time Interval:: Time Interval object
 */
TimeInterval::~TimeInterval(){};

/**
 * @brief check if the actual time is the time where we need to check the sensor (oof)
 * @return true if this is the time
 * @return false either
 */
bool TimeInterval::checkTime()
{
  if ((double)(clock() - this->m_clock) * 1000 / CLOCKS_PER_SEC >= this->m_duration)
  {
    this->m_clock = clock();
    return true;
  }
  return false;
}