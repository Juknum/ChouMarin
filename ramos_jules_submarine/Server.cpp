/**
 * @author Jules Ramos
 * @file Server.cpp
 * @date 20/09/2021
 * @brief Type and method definition for the Server class
 */

#include "Server.hpp"

void Server::dataRcv(float data_p,std::string sensor_p)
{
  if (this->m_consolActivation==true)
  {
    this->consolWrite(data_p);
  }
  if (this->m_logActivation==true)
  {
    this->fileWrite(data_p, sensor_p);
  }
}

void Server::fileWrite(float data_p,std::string sensor_p)
{
  std::string fileName = sensor_p + ".txt";

  std::ofstream file(fileName,std::ios::app);
  if(!file.is_open())
  {
    std::cout<<sensor_p<<" log file couldn't be opened!\n";
  }
  else
  {
    file<<data_p;
  }
  file.close();
  delete fileName;
}

void Server::consolWrite(float data_p)
{
  std::cout<<data_p;
}
