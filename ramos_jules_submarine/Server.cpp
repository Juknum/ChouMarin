/**
 * @author Jules Ramos
 * @file Server.cpp
 * @date 20/09/2021
 * @brief Type and method definition for the Server class
 */

#include "Server.hpp"

void Server::dataRcv(float data_p,EType sensor_p)
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

std::string Server::unitSelection(EType sensor_p)
{
  switch (sensor_p)
  {
    case EType::e_humidity :
    {
      return "% in the air";
    }
    break;

    case EType::e_pression :
    {
      return "hPa";
    }
    break;

    case EType::e_temperature :
    {
      return "°C";
    }
    break;

    case EType::e_sound :
    {
      return "dB";
    }
    break;

    default :
    {
      return " ";
    }
    break;
  }
}

std::string Server::typeToString(EType sensor_p)
{
  switch (sensor_p)
  {
    case EType::e_humidity :
    {
      return "humidity";
    }
    break;

    case EType::e_pression :
    {
      return "pression";
    }
    break;

    case EType::e_temperature :
    {
      return "temperature";
    }
    break;

    case EType::e_sound :
    {
      return "sound";
    }
    break;

    default :
    {
      return "light";
    }
    break;
  }
}


void Server::fileWrite(float data_p,EType sensor_p)
{
  std::string fileName = "../" + this->typeToString(sensor_p) + ".txt"; //for clarity, log files are created outside of the source code folder

  std::ofstream file(fileName,std::ios::app);
  if(!file.is_open())
  {
    std::cout<<this->typeToString(sensor_p)<<" log file couldn't be opened"<<std::endl;
  }
  else
  {
    file<<data_p<<this->unitSelection(sensor_p)<<"\n";
  }
  file.close();
}

void Server::consolWrite(float data_p,EType sensor_p)
{
  std::cout<<data_p<<this->unitSelection(sensor_p)<<std::endl;
}
