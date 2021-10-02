/**
 * @author @Juknum (Julien CONSTANT)
 * @file Server.cpp
 * @date 21/09/2021
 * @brief Server class main file, used to display &/OR write sensors data into the console &/OR sensors files
 */

#include <iostream>
#include <ctime>
#include <string.h>
#include <fstream>

#include "../Includes/Server.hpp"
#include "../Includes/constants.hpp"

/**
 * @brief Construct a new Server:: Server object
 */
Server::Server() : m_consoleActivated(true), m_logsActivated(true) {}

/**
 * @brief Construct a new Server:: Server object with parameters
 * @param consoleOn show console when true
 * @param logsOn enable logs when true
 */
Server::Server(bool consoleOn, bool logsOn) : m_consoleActivated(consoleOn), m_logsActivated(logsOn) {}

/**
 * @brief Write data.value into the console
 * @param data sensor data
 */
void Server::consoleWrite(const SensorData& data)
{

	time_t t = time(0);
	std::string date = ctime(&t);
	date.erase(24, 25); // remove the '\n' at the end

	switch (data.dataType)
	{
		case e_float:
		{
			float f = stof(data.value);
			std::cout << date << " | " << SensorTypeStrings[data.sensorType] << ": " << f << std::endl;
			break;
		}
		case e_int:
		{
			int i = stoi(data.value);
			std::cout << date << " | " << SensorTypeStrings[data.sensorType] << ": " << i << std::endl;
			break;
		}
		case e_bool:
		{
			std::string b = (data.value == "true") ? "true" : "false";
			std::cout << date << " | " << SensorTypeStrings[data.sensorType] << ": " << b << std::endl;
			break;
		}
		case e_unknown_data:
		{
			std::cout << date << " | " << SensorTypeStrings[data.sensorType] << ": " << data.value << std::endl;
			break;
		}
		default:
		{
			break;
		}
	}
};

/**
 * @brief Write data.value into the associated log file
 * @param data sensor data
 */
void Server::fileWrite(const SensorData& data)
{
	std::string buffer = "./Logs/";
	buffer.append(SensorTypeFileNames[data.sensorType]);
	buffer.append(".log");

	time_t t = time(0);
	std::string date = ctime(&t);
	date.erase(24, 25); // remove the '\n' at the end

	std::ofstream logInfo(buffer, std::ios::app);

	logInfo << date << " | SENSOR VALUE: " << data.value << std::endl;

	logInfo.close();
};

/**
 * @brief split incoming data into sub-functions (if enabled)
 * @param data sensor data
 */
void Server::receiveData(const SensorData& data)
{
	if (this->m_consoleActivated)
		this->consoleWrite(data);
	if (this->m_logsActivated)
		this->fileWrite(data);
}

/**
 * @brief use "<<" as operator to receive data from users
 * @param server server where to sent data
 * @param data sensor data
 */
void operator<<(Server& server, const SensorData& data) { server.receiveData(data); }
