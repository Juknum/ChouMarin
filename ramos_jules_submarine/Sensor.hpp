/**
 * @author Jules Ramos
 * @file Sensor.hpp
 * @date 21/09/2021
 * @brief
 */

//
//Define guards
#ifndef SENSOR_HPP_
#define SENSOR_HPP_

#include "Type.hpp"

class Sensor
{
public:
  //TODO: forme canonique

  /**
   * @brief
   * @return
   * @param
   */
  Sensor();

  /**
   * @brief
   * @return
   * @param
   */
  Sensor(Sensor& sensor);

  /**
   * @brief
   * @return
   * @param
   */
  Sensor(Type& type);

  /**
   * @brief
   * @return
   * @param
   */
  ~Sensor();

  /**
   * @brief
   * @return
   * @param
   */
  Type getData();

protected:

  /**
   * @brief
   * @return
   * @param
   */
  Type aleaGenVal();

private:

}



#endif /* SENSOR_HPP_ */
