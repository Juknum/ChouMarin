/**
 * @author @Juknum (Julien CONSTANT)
 * @file Server.cpp
 * @date 21/09/2021
 * @brief Server class main file
 */

#include <iostream>
#include <ctime>
#include <string.h>
#include <fstream>

#include "../Includes/Server.hpp"
#include "../Includes/constants.hpp"

using namespace std;

/**
 * @brief Construct a new Server:: Server object
 */
Server::Server() : consoleActivated(true), logsActivated(true) {}

/**
 * @brief Construct a new Server:: Server object with parameters
 * @param consoleOn show console when true
 * @param logsOn enable logs when true
 */
Server::Server(bool consoleOn, bool logsOn) : consoleActivated(consoleOn), logsActivated(logsOn) {}

/**
 * @brief Write data.value into the console
 * @param data sensor data
 */
void Server::consoleWrite(const SensorData& data) const {

	time_t t = time(0);
	string date = ctime(&t);

	switch (data.dataType) {
		case e_float: {
			float f = stof(data.value);
			cout << SensorTypeStrings[data.sensorType] << " : " << f << " | " << date << endl;
			break;
		}
		case e_int: {
			int i = stoi(data.value);
			cout << SensorTypeStrings[data.sensorType] << " : " << i << " | " << date << endl;
			break;
		}
		case e_bool: {
			string b = (data.value == "true") ? "true" : "false";
			cout << SensorTypeStrings[data.sensorType] << " : " << b << " | " << date << endl;
			break;
		}
		case e_unknown_data: {
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
	string buffer = "./Logs/";
	buffer.append(SensorTypeFileNames[data.sensorType]);
	buffer.append(".log");

	ofstream logInfo(buffer, ios::app);

	logInfo << data.value << endl;

	logInfo.close();
};

/**
 * @brief split incoming data into sub-functions (if enabled)
 * @param data sensor data
 */
void Server::dataRcv(const SensorData& data) const {
	if (this->consoleActivated) this->consoleWrite(data);
	if (this->logsActivated) this->fileWrite(data);
}

/**
 * @brief use "<<" as operator to receive data from users
 * @param server server where to sent data
 * @param data sensor data
 */
void operator<<(Server &server, const SensorData& data) { server.dataRcv(data); }
