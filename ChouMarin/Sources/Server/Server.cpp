/**
 * @file Server.cpp
 * @author @Juknum - Julien CONSTANT (julien.constant@utbm.fr)
 * @brief used to display AND/OR write sensors data into the console/sensors files (in ./Logs)
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

#include "Server.hpp"

#include <ctime>
#include <fstream>

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

	logInfo << date << " | " << data.value << std::endl;

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
