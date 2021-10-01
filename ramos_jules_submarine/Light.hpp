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

  Light():m_sensorType("light"){};
  Light(const Light& light_p):m_sensorType(light_p.m_sensorType){};
  ~Light()
  {
    delete m_sensorType;
  };


  void operator=(const Light& light_p)
  {
    this->m_sensorType = light_p.m_sensorType;
  };

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
