/**
 * @author Jules Ramos
 * @file Server.cpp
 * @date 22/09/2021
 * @brief Type and method declaration for the Sound class
 */

//
//Define guards
#ifndef SOUND_HPP_
#define SOUND_HPP_

#include "Sensor.hpp"

class Sound: public Sensor
{
public:

  Sound();
  Sound(const Sound& sound_p);
  ~Sound();
  void operator=(const Sound& sound_p);

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



#endif /* SOUND_HPP_ */
