/**
 * @author Jules Ramos
 * @file Server.hpp
 * @date 20/09/2021
 * @brief Type and method declaration for the Server class
 */

//
//Define guards
#ifndef SERVER_HPP_
#define SERVER_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include "enums.hpp"

class Server
{
public:

  //canonical form was left in the header as it is pretty short
  Server():m_consolActivation(true),m_logActivation(true){};
  Server(const Server& server_p):m_consolActivation(server_p.m_consolActivation),m_logActivation(server_p.m_logActivation){};
  virtual ~Server(){};
  void operator=(const Server& server_p)
  {
    this->m_consolActivation = server_p.m_consolActivation;
    this->m_logActivation = server_p.m_logActivation;
  };

  /**
   * @brief constructor for custom boolean values
   * @return nothing (constructor)
   * @param bool: console_p for m_consolActivation and log_p for m_logActivation
   */
  Server(bool console_p, bool log_p):m_consolActivation(console_p),m_logActivation(log_p){};

  /**
   * @brief takes the incomming data and displays/logs it
   * @return void
   * @param incomming data: float and the sensor type: EType
   */
  void dataRcv(float data_p,EType sensor_p);

private:

  /**
   * @brief automates the unit output for each sensor, basically a text formatting method
   * @return string: relevant unit
   * @param EType: sensor's type
   */
  std::string unitSelection(EType sensor_p);

  /**
   * @brief automates the EType to string conversion, similar to unitSelection
   * @return string: relevant string
   * @param EType: sensor's type
   */
  std::string typeToString(EType sensor_p);

  /**
   * @brief writes the data of each sensor in its designed log file
   * @return nothing
   * @param incoming data, of float type for now, EType: sensor type to select the log file name and unit
   */
  void fileWrite(float data_p,EType sensor_p);

  /**
   * @brief displays the incoming data in the console
   * @return nothing
   * @param incoming data, of float type for now; EType: sensor type to select the unit
   */
  void consolWrite(float data_p,EType sensor_p);

  bool m_consolActivation; ///< enables or disables the console writing

  bool m_logActivation; ///< enables or disables the log file writing

};


#endif /* SERVER_HPP_ */
