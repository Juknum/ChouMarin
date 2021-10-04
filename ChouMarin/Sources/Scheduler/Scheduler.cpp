/**
 * @file Scheduler.cpp
 * @author @Juknum - Julien CONSTANT (julien.constant@utbm.fr)
 * @brief Schedule event of the submarine IOT
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

#include "Scheduler.hpp"

/**
 * @brief Construct a new Scheduler:: Scheduler object
 */
Scheduler::Scheduler()
{
	// add sensors to the list of sensors
	listSensors.push_back(&this->humiditySensor);
	listSensors.push_back(&this->lightSensor);
	listSensors.push_back(&this->temperatureSensor);
	listSensors.push_back(&this->pressureSensor);

	// add time interval check for sensors
	timeInterval.push_back(TimeInterval(e_humidity, 1000));
	timeInterval.push_back(TimeInterval(e_light, 1000));
	timeInterval.push_back(TimeInterval(e_temperature, 1000));
	timeInterval.push_back(TimeInterval(e_pressure, 1000));

	// watching
	while (true)
	{
		for (int i = 0; i < (int)this->timeInterval.size(); ++i)
		{
			if (timeInterval[i].checkTime())
			{
				for (int j = 0; j < (int)listSensors.size(); j++)
				{
					const SensorData& data = listSensors[j]->getData();

					if (data.sensorType == timeInterval[i].m_sensorType)
					{
						server << listSensors[j]->getData();
					}
				}
			}
		}
	}
};

/**
 * @brief Destroy the Scheduler:: Scheduler object
 */
Scheduler::~Scheduler() {}
