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
#include <fstream>

/**
 * @brief Construct a new Server:: Server object
 */
Server::Server()
{
	this->m_consoleActivated = true;
	this->m_logsActivated = true;
}

/**
 * @brief Construct a new Server:: Server object with parameters
 * @param consoleOn show console when true
 * @param logsOn enable logs when true
 */
Server::Server(bool consoleOn, bool logsOn)
{
	this->m_consoleActivated = consoleOn;
	this->m_logsActivated = logsOn;
}

/**
 * @brief Write data into the console
 * @param data sensor data
 */
void Server::consoleWrite(const SensorData& data)
{
	// clear the console
	// ! This doesn't work in Eclipse IDE console
#if defined _WIN32
	system("cls");
#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
	system("clear");
	//std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences
#elif defined(__APPLE__)
	system("clear");
#endif

	// add data if data ID line is not present
	if (this->m_consoleContent.size() < (unsigned int)(this->m_consoleHeaderLength + 1 + data.id))
	{
		for (unsigned int j = 0; j < this->m_consoleContent.size() - (unsigned int)(this->m_consoleHeaderLength + 1 + data.id); j++)
		{
			this->m_consoleContent.push_back("[" + std::to_string(j) + "] :: waiting for collection...");
		}
	}

	// adjust data
	this->m_consoleContent[this->m_consoleHeaderLength + data.id] = "[" + std::to_string(data.id) + "] :: " + data.time + " | " + SensorTypeStrings[data.sensorType] + " : " + data.value;

	// write data inside the console
	for (unsigned int i = 0; i < this->m_consoleContent.size(); i++)
	{
		std::cout << this->m_consoleContent[i] << std::endl;
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

	std::ofstream logInfo(buffer, std::ios::app);

	logInfo << "[" << data.id << "] :: " << data.time << " | " << data.value << std::endl;

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

/**
 * @brief use "=" as operator to copy attribute of a server to another one
 * @param server 
 * @return Server& 
 */
Server& Server::operator=(const Server& server)
{
	this->m_consoleActivated = server.m_consoleActivated;
	this->m_logsActivated = server.m_logsActivated;
	return *this;
}