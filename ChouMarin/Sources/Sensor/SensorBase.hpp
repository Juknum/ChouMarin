/**
 * @file SensorBase.hpp
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

#ifndef SENSOR_BASE_HPP_
#define SENSOR_BASE_HPP_

#include  "../constants.hpp"

#include <cmath>
#include <limits>

class SensorBase
{
protected:
  SensorData m_data; // data of the sensor

  /**
	 * @brief Random number generator between type min & type max
	 * @tparam T type of the random number
	 * @return T random number between min & max of the given type
	 */
  template <typename T>
  T aleaGenVal()
  {
    T min = std::numeric_limits<T>::min();
    T max = std::numeric_limits<T>::max();
    return aleaGenVal<T>(min, max);
  };

  /**
	 * @brief Random number generator in [min, max]
	 * @tparam T type of the random number
	 */
  template <typename T>
  T aleaGenVal(T min, T max)
  {
    if (min == max)
      return min;
    if (max > RAND_MAX)
      max = RAND_MAX;

    return min + std::fmod(rand(), max - min);
  };

public:
  SensorBase();
  SensorBase(SensorType sT, DataType dT, short unsigned int id);

  virtual ~SensorBase(){};
  virtual const SensorData &getData() = 0; // default value set to 0
};

#endif // SENSOR_BASE_HPP_