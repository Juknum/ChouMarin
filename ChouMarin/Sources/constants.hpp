/**
 * @file constants.hpp
 * @author @Juknum - Julien CONSTANT (julien.constant@utbm.fr)
 * @brief file where all constants and so on are written
 * @date 2021-09-21
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

#ifndef CONSTANTS_HPP_
#define CONSTANTS_HPP_

// libs below are declared to be easily used everywhere in the project
#include <string>
#include <iostream>
#include <ctime>

/**
 * @brief types for data value of a sensor
 */
enum DataType
{
	e_unknown_data,
	e_float,
	e_int,
	e_bool
};

/**
 * @brief types (names) for sensor
 */
enum SensorType
{
	e_unknown_type,
	e_temperature,
	e_humidity,
	e_light,
	e_pressure
};

/**
 * @brief corresponding enum to strings
 * ! strings must match position of their corresponding enum
 */
const std::string SensorTypeStrings[5]
{
	"UNKNOWN_TYPE",
	"TEMPERATURE ",
	"HUMIDITY    ",
	"LIGHT       ",
	"PRESSURE    "
};

/**
 * @brief corresponding enum to file names
 * ! strings must match position of their corresponding enum
 */
const std::string SensorTypeFileNames[5]
{
	"sensor_unknown",
	"sensor_temperature",
	"sensor_humidity",
	"sensor_light",
	"sensor_pressure"
};

/**
 * @brief Structure associated to the sensor
 * @param SensorType type of sensor (name of the sensor)
 * @param DataType type of data (int, float...)
 * @param value value of the data
 */
typedef struct s_SensorData
{
	SensorType sensorType;
	DataType dataType;
	std::string value;
	std::string time;
} SensorData;

#endif // CONSTANTS_HPP_
