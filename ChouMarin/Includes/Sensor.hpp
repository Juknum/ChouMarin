/**
 * @author @Juknum (Julien CONSTANT)
 * @file Sensor.hpp
 * @date 27/09/2021
 * @brief Sensor class header file, used as "parent" for all sensors types
 */

#ifndef SENSOR_H_
#define SENSOR_H_

#include <cmath>
#include <limits>
#include "constants.hpp"

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
		if (min == max) return min;
		if (max > RAND_MAX) max = RAND_MAX;

		return min + std::fmod(rand(), max - min);
	};

public:
	SensorBase();
	SensorBase(SensorType sT, DataType dT);

	virtual ~SensorBase(){};
	virtual const SensorData& getData() = 0; // default value set to 0
};

// template for all existing sensors
template <class T>
class Sensor : public SensorBase
{
protected:
	T m_value;

public:
	Sensor<T>();
	Sensor<T>(SensorType sT, DataType dT) : SensorBase(sT, dT), m_value(){};

	virtual ~Sensor(){};
	virtual const SensorData& getData() = 0;
};

#endif // SENSOR_H_
