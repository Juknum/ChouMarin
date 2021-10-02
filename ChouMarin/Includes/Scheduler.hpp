/**
 * @author @Juknum (Julien CONSTANT)
 * @file Scheduler.hpp
 * @date 27/09/2021
 * @brief Scheduler class header file
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include <vector>
#include <time.h>

#include "Server.hpp"
#include "sensors/HumiditySensor.hpp"
#include "sensors/LightSensor.hpp"
#include "sensors/TemperatureSensor.hpp"
#include "sensors/PressureSensor.hpp"

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

class Scheduler
{
public:
	Scheduler();
	virtual ~Scheduler();

private:
	Server server;
	LightSensor lightSensor;
	HumiditySensor humiditySensor;
	TemperatureSensor temperatureSensor;
	PressureSensor pressureSensor;
	std::vector<SensorBase*> listSensors;
	std::vector<TimeInterval> timeInterval;
};

#endif // SCHEDULER_H_