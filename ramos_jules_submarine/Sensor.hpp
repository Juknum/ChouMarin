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
#include <ctime>
#include "enums.hpp"

class Sensor
{
public:

  //this is an abstract class therefore there is no canonical form other than a virtual destructor
  virtual ~Sensor(){};

  /**
   * @brief getter for the m_sensorType attribute
   * @return EType: m_sensorType
   * @param none
   */
  EType getSensorType();

protected:

  /**
   * @brief generates a random value of data
   * @return a float: the new data value
   * @param none
   */
  virtual float aleaGenVal()=0;

  EType m_sensorType; ///< stocks the kind of sensor initialized for an easier log file finding

private:

};

#endif /* SENSOR_HPP_ */
