/**
 * @author Jules Ramos
 * @file Server.cpp
 * @date 22/09/2021
 * @brief Type and method definition for the Humidity class
 */

#include "Humidity.hpp"

Humidity::Humidity()
{
  this->m_sensorType = "humidity";
};

Humidity::Humidity(const Humidity& humidity_p)
{
  this->m_sensorType=humidity_p.m_sensorType;
};

Humidity::~Humidity(){};

void Humidity::operator=(const Humidity& humidity_p)
{
  this->m_sensorType = humidity_p.m_sensorType;
};

float Humidity::aleaGenVal()
{
  return (rand()%351+400)/10; //from 40.0 to 75.0, will stay a float
}

float Humidity::getData()
{
  return this->aleaGenVal();
}
