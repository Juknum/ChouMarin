/**
 * @author Jules Ramos
 * @file Server.cpp
 * @date 22/09/2021
 * @brief Type and method definition for the Temperature class
 */

#include "Temperature.hpp"

Temperature::Temperature()
{
  m_sensorType="temperature";
};

Temperature::Temperature(const Temperature& temperature_p)
{
  m_sensorType=temperature_p.m_sensorType;
};

Temperature::~Temperature(){};

void Temperature::operator=(const Temperature& temperature_p)
{
  this->m_sensorType = temperature_p.m_sensorType;
};

float Temperature::aleaGenVal()
{
  return rand()%100; //from 0 to 99, placeholder, to be reworked after the inheritance
}

float Temperature::getData()
{
  return this->aleaGenVal();
}
