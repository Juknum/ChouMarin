#ifndef LIGHT_SENSOR_H_
#define LIGHT_SENSOR_H_

#include "../../../Includes/Sensor.hpp"

class LightSensor: public Sensor<bool> {
  public:
    LightSensor();
    virtual ~LightSensor();
    const SensorData& getData();
};

#endif // LIGHT_SENSOR_H_