/**
 * @file Server.hpp
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

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include "../constants.hpp"
#include <vector>
class Server
{
private:
	bool m_consoleActivated; // if true: console sensor data
	bool m_logsActivated;		 // if true: log sensor data into files at ./Logs/<sensorName>

	const unsigned int m_consoleHeaderLength = 6;
	std::vector <std::string> m_consoleContent // content displayed on the console
	{
		"",
		"                                 |_",
		"  > SUBMARINE IOT          _____|~ |____",
		"   - Julien CONSTANT      (  --         ~~~~--_,",
		"                            ~~~~~~~~~~~~~~~~~~~'`",
		"SENSORS:" // sensors values are displayed below
	};

	/**
	 * ! As the subject is rather free on the properties of this 2 functions below,
	 * ! I've choosen to make them private & access them trough receiveData()
	 */
	void fileWrite(const SensorData& data);
	void consoleWrite(const SensorData& data);

public:
	Server();
	Server(bool consoleOn, bool logsOn);
	virtual ~Server() {};

	void receiveData(const SensorData& data);

	Server& operator=(const Server& server);
};

void operator<<(Server& server, const SensorData& data);


#endif // SERVER_HPP_
