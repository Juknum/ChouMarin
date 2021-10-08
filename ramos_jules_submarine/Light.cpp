/**
 * @author Jules Ramos
 * @file Server.cpp
 * @date 22/09/2021
 * @brief Type and method definition for the Light class
 */

#include "Light.hpp"

Light::Light()
{
  this->m_sensorType=EType::e_light;
};

Light::Light(const Light& light_p)
{
  this->m_sensorType=light_p.m_sensorType;
};

Light::~Light(){};

void Light::operator=(const Light& light_p)
{
  this->m_sensorType = light_p.m_sensorType;
};

float Light::aleaGenVal()
{
  return rand()%2; //0 or 1, will become boolean
}

float Light::getData()
{
  return this->aleaGenVal();
}
