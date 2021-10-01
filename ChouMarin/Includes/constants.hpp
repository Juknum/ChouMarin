/**
 * @author @Juknum (Julien CONSTANT)
 * @file Constants.hpp
 * @date 21/09/2021
 * @brief file where all constants and so on are written
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#include <string>

/**
 * @brief types for data value of a sensor
 */
enum DataType {
	e_unknown_data,
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
 * ! strings must match position of their corresponding enum
 */
const std::string SensorTypeStrings[5] {
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
const std::string SensorTypeFileNames[5] {
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
typedef struct s_SensorData {
	SensorType sensorType;
	DataType dataType;
	std::string value;
} SensorData;

#endif // CONSTANTS_H_
