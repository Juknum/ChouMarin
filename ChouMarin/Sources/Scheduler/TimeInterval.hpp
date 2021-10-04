/**
 * @file TimeInterval.hpp
 * @author @Juknum - Julien CONSTANT (julien.constant@utbm.fr)
 * @brief Manage time for sensors
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

#ifndef TIME_INTERVAL_HPP_
#define TIME_INTERVAL_HPP_

#include <time.h>
#include "../constants.hpp"

class TimeInterval
{
  friend class Scheduler; // to easily access this class from the scheduler

private:
  SensorType m_sensorType;
  clock_t m_clock;
  int m_duration; // duration in ms
public:
  TimeInterval();
  TimeInterval(SensorType sensorType, int duration);
  virtual ~TimeInterval();
  bool checkTime();
};

#endif // TIME_INTERVAL_HPP_
