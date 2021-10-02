/**
 * @author Jules Ramos
 * @file Server.cpp
 * @date 22/09/2021
 * @brief Type and method declaration for the Temperature class
 */

//
//Define guards
#ifndef TEMPERATURE_HPP_
#define TEMPERATURE_HPP_

#include "Sensor.hpp"

class Temperature: public Sensor
{
public:

  Temperature();
  Temperature(const Temperature& temperature_p);
  ~Temperature();
  void operator=(const Temperature& temperature_p);

  /**
   * @brief calls upon aleaGenVal and gives the generated data
   * @return the generated data: float
   * @param none
   */
  float getData();

private:

  /**
   * @brief generates a random value of data
   * @return a float: the new data value
   * @param none
   */
  float aleaGenVal();
};



#endif /* TEMPERATURE_HPP_ */
