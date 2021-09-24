/**
 * @author @Juknum (Julien CONSTANT)
 * @file Server.cpp
 * @date 21/09/2021
 * @brief Server class main file
 */

#include <iostream>
#include <string.h>
#include <fstream>

#include "Server.hpp"
#include "constants.hpp"

using namespace std;

/**
 * @brief Construct a new Server:: Server object
 */
Server::Server() : consoleActivated(), logsActivated() {}

/**
 * @brief Construct a new Server:: Server object with parameters
 * @param consoleOn show console when true
 * @param logsOn enable logs when true
 */
Server::Server(bool consoleOn, bool logsOn) : consoleActivated(consoleOn), logsActivated(logsOn) {}

/**
 * @brief Construct a new Server:: Server object from another server
 * @param server server
 */
Server::Server(const Server& server) : consoleActivated(server.consoleActivated), logsActivated(server.logsActivated) {}

/**
 * @brief Copy a server from the given server
 * @param server server
 * @return Server& 
 */
Server& Server::operator=(Server const& server) {
	this->consoleActivated = server.consoleActivated;
	this->logsActivated = server.consoleActivated;
	return *this;
}

/**
 * @brief Write data.value into the console
 * @param data sensor data
 */
void Server::consoleWrite(const SensorData& data) const {
	switch (data.dataType) {
		case e_float: {
			float f = atof(data.value);
			cout << SensorTypeStrings[data.sensorType] << "\t:\t" << f << endl;
			break;
		}
		case e_int: {
			int i = atoi(data.value);
			cout << SensorTypeStrings[data.sensorType] << "\t:\t" << i << endl;
			break;
		}
		case e_bool: {
			bool b = (strcmp("true", data.value) == 0) ? true : false;
			cout << SensorTypeStrings[data.sensorType] << "\t:\t" << b << endl;
			break;
		}
		case e_unknown: {
			break;
		}
		default: {
			break;
		}
	}
};

/**
 * @brief Write data.value into the associated log file
 * @param data sensor data
 */
void Server::fileWrite(const SensorData& data) const {
	string buffer;
	buffer.assign(SensorTypeStrings[data.sensorType]);
	buffer.append(".log");

	ofstream logInfo(buffer, ios::app);

	if (data.dataType == e_bool) logInfo << ((strcmp("true", data.value) == 0) ? true : false) << endl; // can only be true OR false
	else logInfo << data.value << endl;                                                                 // can be anything

	logInfo.close();
};

/**
 * @brief split incoming data into sub-functions (if enabled)
 * @param data sensor data
 */
void Server::dataReceive(const SensorData& data) const {
	if (this->consoleActivated) this->consoleWrite(data);
	if (this->logsActivated) this->fileWrite(data);
}

/**
 * @brief use "<<" as operator to receive data from users
 * @param server server where to sent data
 * @param data sensor data
 */
void operator<<(Server &server, const SensorData& data) { server.dataReceive(data); }
