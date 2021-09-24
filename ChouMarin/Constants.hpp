/**
 * @author @Juknum (Julien CONSTANT)
 * @file Constants.hpp
 * @date 21/09/2021
 * @brief file where all constants and so on are written
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#include <string.h>
#include <map>

#define STRING_LENGTH 16

/**
 * @brief types for data value of a sensor
 */
enum DataType {
	e_unknown,
	e_float,
	e_int,
	e_bool
};

/**
 * @brief types (names) for sensor
 */
enum SensorType {
	e_unknown_type,
	e_temperature,
	e_humidity,
	e_light,
	e_pressure
};

/**
 * @brief corresponding enum to strings
 */
typedef std::map<SensorType, std::string> SensorTypeMap;
SensorTypeMap SensorTypeStrings {
	{ e_unknown_type, std::string("UNKNOWN_TYPE")},
	{ e_temperature, std::string("TEMPERATURE")},
	{ e_humidity, std::string("HUMIDITY")},
	{ e_light, std::string("LIGHT")},
	{ e_pressure, std::string("PRESSURE")}
};

/**
 * @brief Structure associated to the sensor
 * @param SensorType type of sensor (name of the sensor)
 * @param DataType type of data (int, float...)
 * @param value value of the data
 */
typedef struct s_SensorData {
	SensorType sensorType;
	DataType dataType;
	char *value;
} SensorData;

#endif // CONSTANTS_H_
