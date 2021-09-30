#ifndef TEMPERATURE_SENSOR_H_
#define TEMPERATURE_SENSOR_H_

#include "../../../Includes/Sensor.hpp"

class TemperatureSensor: public Sensor<float> {
  public:
    TemperatureSensor();
    virtual ~TemperatureSensor();
    const SensorData& getData();
};

#endif // TEMPERATURE_SENSOR_H_