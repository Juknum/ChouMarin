/**
 * @file Scheduler.hpp
 * @author @Juknum - Julien CONSTANT (julien.constant@utbm.fr)
 * @brief Schedule event in the submarine IOT
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

#ifndef SCHEDULER_HPP_
#define SCHEDULER_HPP_

#include <vector>
#include <time.h>

#include "TimeInterval.hpp"
#include "../Server/Server.hpp"
#include "../Sensor/AllSensors/HumiditySensor.hpp"
#include "../Sensor/AllSensors/LightSensor.hpp"
#include "../Sensor/AllSensors/TemperatureSensor.hpp"
#include "../Sensor/AllSensors/PressureSensor.hpp"

class Scheduler
{
public:
	Scheduler();
	virtual ~Scheduler();

private:
	Server server;
	LightSensor lightSensor = LightSensor(3);
	HumiditySensor humiditySensor = HumiditySensor(1);
	TemperatureSensor temperatureSensor = TemperatureSensor(2);
	PressureSensor pressureSensor = PressureSensor(0);
	std::vector<SensorBase*> listSensors;
	std::vector<TimeInterval> timeInterval;
};

#endif // SCHEDULER_HPP_