/**
 * @author Jules Ramos
 * @file Server.cpp
 * @date 20/09/2021
 * @brief Type and method definition for the Server class
 */

#include "Server.hpp"

Server::Server()
{
  this->m_consolActivation = true;
  this->m_logActivation = true;
}

Server::Server(const Server& server)
{
  this->m_consolActivation = server.m_consolActivation;
  this->m_logActivation = server.m_logActivation;
}

Server::~Server()
{
  //nothing to free here for now;
}

void Server::operator=(const Server& server)
{
  this->m_consolActivation = server.m_consolActivation;
  this->m_logActivation = server.m_logActivation;
}

ostream& Server::operator<<(ostream& os, float data)
{
  os<<data<<"\n";
  return os;
}

void Server::dataRcv(float data)
{
  //TODO: this
}

void Server::fileWrite(float data)
{
  ofstream file("log.txt",ios::app); //TODO: different log files depending on the sensor
  if(!file.is_open())
  {
    std::cout<<"log file couldn't be opened!\n";
  }
  else
  {
    file<<data;
  }
  file.close();
}

void Server::consolWrite(float data)
{
  std::cout<<data;
}
