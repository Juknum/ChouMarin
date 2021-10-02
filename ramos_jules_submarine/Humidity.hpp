/**
 * @author Jules Ramos
 * @file Server.cpp
 * @date 22/09/2021
 * @brief Type and method declaration for the Humidity class
 */

//
//Define guards
#ifndef HUMIDITY_HPP_
#define HUMIDITY_HPP_

#include "Sensor.hpp"

class Humidity: public Sensor
{
public:

  Humidity();
  Humidity(const Humidity& humidity_p);
  ~Humidity();
  void operator=(const Humidity& humidity_p);

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



#endif /* HUMIDITY_HPP_ */
