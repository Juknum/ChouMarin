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

using namespace std;

class Server
{
public:

  /**
   * @brief default constructor
   * @return nothing
   * @param none
   */
  Server();

  /**
   * @brief copy constructor
   * @return nothing
   * @param copied Server object reference
   */
  Server(const Server& server);

  /**
   * @brief destructor
   * @return nothing
   * @param none
   */
  virtual ~Server();

  /**
   * @brief affectation operator overload
   * @return nothing
   * @param copied Server object reference
   */
  void operator=(const Server& server);

  /**
   * @brief << operator overload
   * @return nothing
   * @param displayed thing
   */
  ostream& operator<<(ostream& os, float data);

  /**
   * @brief
   * @return
   * @param
   */
  void dataRcv(float data);

private:

  /**
   * @brief writes the data of each sensor in its designed log file
   * @return nothing
   * @param incoming data, of float type for now
   */
  void fileWrite(float data);

  /**
   * @brief displays the incoming data in the console
   * @return nothing
   * @param incoming data, of float type for now
   */
  void consolWrite(float data);

  bool m_consolActivation; //enables or disables the console writing

  bool m_logActivation; //enables or disables the log file writing

};



#endif /* SERVER_HPP_ */
