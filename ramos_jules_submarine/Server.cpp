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
    this->consolWrite(data_p,sensor_p);
  }
  if (this->m_logActivation==true)
  {
    this->fileWrite(data_p, sensor_p);
  }
}

std::string Server::unitSelection(std::string sensor_p)
{ // can't use a switch, might have to be reworked later on
  if (sensor_p=="humidity")
  {
    return "% in the air";
  }

  if (sensor_p=="temperature")
  {
    return "°C";
  }

  if (sensor_p=="pression")
  {
    return "hPa";
  }

  if (sensor_p=="sound")
  {
    return "dB";
  }

  return " "; //case of light
}

void Server::fileWrite(float data_p,std::string sensor_p)
{
  std::string fileName = "../" + sensor_p + ".txt"; //for clarity, log files are created outside of the source code folder

  std::ofstream file(fileName,std::ios::app);
  if(!file.is_open())
  {
    std::cout<<sensor_p<<" log file couldn't be opened"<<std::endl;
  }
  else
  {
    file<<data_p<<this->unitSelection(sensor_p)<<"\n";
  }
  file.close();
}

void Server::consolWrite(float data_p,std::string sensor_p)
{
  std::cout<<data_p<<this->unitSelection(sensor_p)<<std::endl;
}
