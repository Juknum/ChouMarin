/**
 * @author Jules Ramos
 * @file Server.cpp
 * @date 01/10/2021
 * @brief Type and method definition for the Pressure class
 */


#include "Pressure.hpp"

float Pressure::aleaGenVal()
{
  return rand()%100; //from 0 to 99, placeholder, to be reworked after the inheritance
}

float Pressure::getData()
{
  return this->aleaGenVal();
}
