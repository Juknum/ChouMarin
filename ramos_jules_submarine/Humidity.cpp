/**
 * @author Jules Ramos
 * @file Server.cpp
 * @date 22/09/2021
 * @brief Type and method definition for the Humidity class
 */

#include "Humidity.hpp"

float Humidity::aleaGenVal()
{
  return rand()%100; //from 0 to 99, placeholder, to be reworked after the inheritance
}

float Humidity::getData()
{
  return this->aleaGenVal();
}
