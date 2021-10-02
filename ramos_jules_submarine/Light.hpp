/**
 * @author Jules Ramos
 * @file Server.cpp
 * @date 22/09/2021
 * @brief Type and method declaration for the Light class
 */

//
//Define guards
#ifndef LIGHT_HPP_
#define LIGHT_HPP_

#include "Sensor.hpp"

class Light: public Sensor
{
public:

  Light();
  Light(const Light& light_p);
  ~Light();
  void operator=(const Light& light_p);

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



#endif /* LIGHT_HPP_ */
