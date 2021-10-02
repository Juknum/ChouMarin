/**
 * @author @Juknum (Julien CONSTANT)
 * @file Server.hpp
 * @date 21/09/2021
 * @brief Server class header file
 */

#ifndef SERVER_H_
#define SERVER_H_

#include "constants.hpp"

class Server
{
private:
	bool m_consoleActivated; // if true: console sensor data
	bool m_logsActivated;		 // if true: log sensor data into files at ./Logs/<sensorName>

	/**
	 * ! As the subject of this project is always changing the type of the two functions below,
	 * ! I've taken the liberty to make them private & access them trough receiveData()
	 * ! This public function decide where the data should go
	 */
	void fileWrite(const SensorData& data);
	void consoleWrite(const SensorData& data);

public:
	Server();
	Server(bool, bool);
	virtual ~Server(){};
	void receiveData(const SensorData& data);
};

void operator<<(Server& server, const SensorData& data);

#endif // SERVER_H_
