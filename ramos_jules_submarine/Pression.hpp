/**
 * @author Jules Ramos
 * @file Server.cpp
 * @date 01/10/2021
 * @brief Type and method declaration for the Pression class
 */

#ifndef PRESSION_HPP_
#define PRESSION_HPP_


#include "Sensor.hpp"

class Pression: public Sensor
{
public:

  Pression();
  Pression(const Pression& pression_p);
  ~Pression();
  void operator=(const Pression& pression_p);

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


#endif /* PRESSION_HPP_ */
