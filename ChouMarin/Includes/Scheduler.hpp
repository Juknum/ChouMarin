/**
 * @author @Juknum (Julien CONSTANT)
 * @file Scheduler.hpp
 * @date 27/09/2021
 * @brief Scheduler class header file
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include <vector>
#include <time.h>

#include "Server.hpp"
#include "../Sources/Sensors/headers/HumiditySensor.hpp"
#include "../Sources/Sensors/headers/LightSensor.hpp"
#include "../Sources/Sensors/headers/TemperatureSensor.hpp"

class TimeInterval {
  friend class Scheduler;

  public:
    TimeInterval();
    TimeInterval(SensorType sensorType, int duration);
    virtual ~TimeInterval();
    bool checkTime();

  private:
    SensorType sensorType;
    clock_t tClock;
    int duration; // duration in ms
};

class Scheduler {
public:
  Scheduler();
  virtual ~Scheduler();

private:
  Server server;
  LightSensor lightSensor;
  HumiditySensor humiditySensor;
  TemperatureSensor temperatureSensor;
  // TODO: add all sensors here
  std::vector<SensorBase*> listSensors;
  std::vector<TimeInterval> timeInterval;
};

#endif // SCHEDULER_H_