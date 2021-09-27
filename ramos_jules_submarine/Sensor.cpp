/**
 * @author Jules Ramos
 * @file Sensor.cpp
 * @date 21/09/2021
 * @brief Type and method definition for the Sensor class
 */

#include "Sensor.hpp"


Sensor::Sensor()
{
  this->m_data = 0;
}

Sensor::Sensor(const Sensor& sensor)
{
  this->m_data = sensor.m_data;
}

Sensor::Sensor(float data)
{
  this->m_data = data;
}

Sensor::~Sensor()
{
  //nothing to destroy
}

void Sensor::operator=(const Sensor& sensor)
{
  //nothing to give here
}

float Sensor::getData()
{
  return this->m_data;
}

float Sensor::aleaGenVal()
{
  this->m_data = rand()%100; //from 0 to 99, placeholder, to be reworked after the inheritance
  return this->m_data;
}
