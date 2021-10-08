/**
 * @author Jules Ramos
 * @file Sensor.cpp
 * @date 03/10/2021
 * @brief Type and method definition for the abstract Sensor class
 */

#include "Sensor.hpp"

EType Sensor::getSensorType()
{
  return this->m_sensorType;
}
