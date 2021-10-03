/**
 * @author Jules Ramos
 * @file Server.cpp
 * @date 01/10/2021
 * @brief Type and method definition for the Pression class
 */


#include "Pression.hpp"

Pression::Pression()
{
  this->m_sensorType="pression";
};

Pression::Pression(const Pression& pression_p)
{
  this->m_sensorType=pression_p.m_sensorType;
};

Pression::~Pression(){};

void Pression::operator=(const Pression& pression_p)
{
  this->m_sensorType = pression_p.m_sensorType;
};

float Pression::aleaGenVal()
{
  return rand()%17 + 1005; //from 1005 to 1021 hPa, will stay an integer
}

float Pression::getData()
{
  return this->aleaGenVal();
}
