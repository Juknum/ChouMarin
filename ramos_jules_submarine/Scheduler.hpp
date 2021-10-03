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

#include <chrono>
#include <thread>
/*
 * making the assumption this code will be compiled and run with at least C++1 to get a
 * crossplatform and included in the c++ standards waiting solution
 */

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
  Scheduler(const Scheduler& scheduler_p);
  ~Scheduler();
  void operator=(const Scheduler& scheduler_p);

  /**
   * @brief constructor for a custom server log and console activation
   * @return none (constructor)
   * @param log_p: bool, becomes logActivation in the server; console_p: bool, becomes logActivation
   */
  Scheduler(bool console_p,bool log_p);

  /**
   * @brief invokes the dataReceive of a Server with the proper methods of a sensor,
   * automating the link between servers and sensors for a better extensibility
   * !!! T must be a derived class of Sensor !!! template makes this method usable for all of them
   * @return none, the server handles the output
   * @param Server: output server, Sensor: the sensor that the server must collect data from
   */

  template <class T> void SendToServer(Server& server_p, T& sensor_p);

  /**
   * @brief loop of data collecting and writing, basically the core of this program, calls upon the SendToServer method
   * @return none, SendToServer handles the output
   * @param none for now, might add custom collect time intervals for the final version
   */
  void Launch();

private:

  Server m_server;
  Light m_light;
  Temperature m_temperature;
  Humidity m_humidity;
  Sound m_sound;
  Pression m_pression;
};

#endif /* SCHEDULER_HPP_ */
