/**
 * @author Jules Ramos
 * @file Server.cpp
 * @date 01/10/2021
 * @brief Type and method declaration for the Pressure class
 */

#ifndef PRESSURE_HPP_
#define PRESSURE_HPP_


#include "Sensor.hpp"

class Pressure: public Sensor
{
public:

  Pressure():m_sensorType("Pressure"){};
  Pressure(const Pressure& pressure_p):m_sensorType(pressure_p.m_sensorType){};
  ~Pressure()
  {
    delete m_sensorType;
  };


  void operator=(const Pressure& pressure_p)
  {
    this->m_sensorType = pressure_p.m_sensorType;
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


#endif /* PRESSURE_HPP_ */
