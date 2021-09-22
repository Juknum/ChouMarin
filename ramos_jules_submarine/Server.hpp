/**
 * @author Jules Ramos
 * @file Server.hpp
 * @date 20/09/2021
 * @brief
 */

//
//Define guards
#ifndef SERVER_HPP_
#define SERVER_HPP_

#include "Type.hpp"

class Server
{
public:
  //TODO: forme canonique

  /**
   * @brief
   * @return
   * @param
   */
  Server();

  /**
   * @brief
   * @return
   * @param
   */
  Server(Server& server);

  /**
   * @brief
   * @return
   * @param
   */
  ~Server();

  /**
   * @brief
   * @return
   * @param
   */
  void operator=(Server& server);

  /**
   * @brief
   * @return
   * @param
   */
  void operator<<(Type& type);

  /**
   * @brief
   * @return
   * @param
   */
  void dataRcv(Type& type);

private:

  /**
   * @brief
   * @return
   * @param
   */
  void fileWrite(Type& type);

  /**
   * @brief
   * @return
   * @param
   */
  void consolWrite(Type& type);

  bool m_consolActivation; //TODO: description

  bool m_logActivation; //TODO: description

};



#endif /* SERVER_HPP_ */
