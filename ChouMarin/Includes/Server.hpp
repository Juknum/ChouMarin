/**
 * @author @Juknum (Julien CONSTANT)
 * @file Server.hpp
 * @date 21/09/2021
 * @brief Server class header file
 */

#ifndef SERVER_H_
#define SERVER_H_

#include "constants.hpp"

class Server {
	private:
		bool consoleActivated; // if true: console sensor data
		bool logsActivated;    // if true: log sensor data into files at ./Logs/<sensorName>
	public:
		Server();
		Server(bool, bool);
		virtual ~Server() {};

		void dataRcv(const SensorData& data) const;
		void fileWrite(const SensorData& data) const;
		void consoleWrite(const SensorData& data) const;
};

void operator<<(Server &server, const SensorData &data);

#endif // SERVER_H_
