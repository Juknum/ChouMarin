/**
 * @author Jules Ramos
 * @file Scheduler.hpp
 * @date 21/09/2021
 * @brief Type and method declaration for the Scheduler class
 */

//
//Define guards
#ifndef SCHEDULER_HPP_
#define SCHEDULER_HPP_

#include "Server.hpp"
#include "Light.hpp"
#include "Temperature.hpp"
#include "Sound.hpp"
#include "Humidity.hpp"
#include "Pression.hpp"

class Scheduler
{
public:

  Scheduler();

private:

  Server m_server;
  Light m_light;
  Temperature m_temperature;
  Humidity m_humidity;
  Sound m_sound;
  Pression m_pression;
};

#endif /* SCHEDULER_HPP_ */
