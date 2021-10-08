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

#include <iostream>
#include <csignal>

//TODO: make these work
#include <chrono>
#include <thread>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#define Sleep(x) usleep((x)*1000)
#endif
/*
 * making a macro because I couldn't get threads to work, this is my best shot at a cross platform solution
 * for the waiting times
 * I programmed on Windows
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

  Server m_server; ///< stocks the associated server
  Light m_light; //< stocks the submarine's light sensor
  Temperature m_temperature; ///< stocks the temperature sensor
  Humidity m_humidity; ///< stocks the humidity sensor
  Sound m_sound; ///< stocks the sound sensor
  Pression m_pression; ///< stocks the pressure sensor
};

#endif /* SCHEDULER_HPP_ */
