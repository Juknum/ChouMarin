/**
 * @author Jules Ramos
 * @file Sensor.hpp
 * @date 21/09/2021
 * @brief Type and method declaration for the abstract Sensor class
 */

//
//Define guards
#ifndef SENSOR_HPP_
#define SENSOR_HPP_

#include <cstdlib>
#include <string>

virtual class Sensor
{
public:

  //this is an abstract class therefore there is no canonical form other than a virtual destructor
  virtual ~Sensor();

protected:

  /**
   * @brief generates a random value of data
   * @return a float: the new data value
   * @param none
   */
  virtual float aleaGenVal()=0;

private:

  std::string m_sensorType; //stocks the kind of sensor initialized for an easier log file finding
};

#endif /* SENSOR_HPP_ */
