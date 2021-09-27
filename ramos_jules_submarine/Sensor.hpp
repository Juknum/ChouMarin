/**
 * @author Jules Ramos
 * @file Sensor.hpp
 * @date 21/09/2021
 * @brief Type and method declaration for the Sensor class
 */

//
//Define guards
#ifndef SENSOR_HPP_
#define SENSOR_HPP_

#include <cstdlib>

class Sensor
{
public:

  /**
   * @brief default constructor
   * @return nothing
   * @param none
   */
  Sensor();

  /**
   * @brief copy constructor
   * @return nothing
   * @param copied Sensor object reference
   */
  Sensor(const Sensor& sensor);

  /**
   * @brief constructor with a specific m_data initialization
   * @return nothing
   * @param float: wanted value for m_data
   */
  Sensor(float data);

  /**
   * @brief destructor
   * @return nothing
   * @param none
   */
  virtual ~Sensor();

  /**
   * @brief = operator overload
   * @return nothing
   * @param Sensor object reference
   */
  void operator=(const Sensor& sensor);

  /**
   * @brief getter for the m_data attribute
   * @return m_data, float
   * @param none
   */
  float getData();

protected:

  /**
   * @brief generates a random value for the m_data attribute
   * @return a float: the new data value
   * @param none
   */
  float aleaGenVal();

private:

  float m_data; // stocks the data "measured" by the sensor until it is sent
};



#endif /* SENSOR_HPP_ */
