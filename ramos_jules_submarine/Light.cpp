/**
 * @author Jules Ramos
 * @file Server.cpp
 * @date 22/09/2021
 * @brief Type and method definition for the Light class
 */

#include "Light.hpp"

Light::Light()
{
  m_sensorType="light";
};

Light::Light(const Light& light_p)
{
  m_sensorType=light_p.m_sensorType;
};

Light::~Light(){};

void Light::operator=(const Light& light_p)
{
  this->m_sensorType = light_p.m_sensorType;
};

float Light::aleaGenVal()
{
  return rand()%100; //from 0 to 99, placeholder, to be reworked after the inheritance
}

float Light::getData()
{
  return this->aleaGenVal();
}
