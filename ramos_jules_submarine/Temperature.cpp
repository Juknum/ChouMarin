/**
 * @author Jules Ramos
 * @file Server.cpp
 * @date 22/09/2021
 * @brief Type and method definition for the Temperature class
 */

#include "Temperature.hpp"

Temperature::Temperature()
{
  this->m_sensorType="temperature";
};

Temperature::Temperature(const Temperature& temperature_p)
{
  this->m_sensorType=temperature_p.m_sensorType;
};

Temperature::~Temperature(){};

void Temperature::operator=(const Temperature& temperature_p)
{
  this->m_sensorType = temperature_p.m_sensorType;
};

float Temperature::aleaGenVal()
{
  return (rand()%110+150)/10.0; //from 15.0 to 25.9, will stay a float
}

float Temperature::getData()
{
  return this->aleaGenVal();
}
