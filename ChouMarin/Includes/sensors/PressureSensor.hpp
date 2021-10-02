/**
 * @author @Juknum (Julien CONSTANT)
 * @file PressureSensor.hpp
 * @date 30/09/2021
 * @brief Temperature sensor header file
 */

#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_

#include "../Sensor.hpp"

class PressureSensor : public Sensor<int>
{
public:
	PressureSensor();
	virtual ~PressureSensor();
	const SensorData& getData();
};

#endif // PRESSURE_SENSOR_H_