/**
 * @author Jules Ramos
 * @file Server.cpp
 * @date 01/10/2021
 * @brief Type and method definition for the Pression class
 */


#include "Pression.hpp"

Pression::Pression()
{
  m_sensorType="Pression";
};

Pression::Pression(const Pression& pression_p)
{
  m_sensorType=pression_p.m_sensorType;
};

Pression::~Pression(){};

void Pression::operator=(const Pression& pression_p)
{
  this->m_sensorType = pression_p.m_sensorType;
};

float Pression::aleaGenVal()
{
  return rand()%100; //from 0 to 99, placeholder, to be reworked after the inheritance
}

float Pression::getData()
{
  return this->aleaGenVal();
}
