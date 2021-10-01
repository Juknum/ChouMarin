/**
 * @author @Juknum (Julien CONSTANT)
 * @file LightSensor.hpp
 * @date 27/09/2021
 * @brief Light sensor class header file
 */

#ifndef LIGHT_SENSOR_H_
#define LIGHT_SENSOR_H_

#include "../Sensor.hpp"

class LightSensor: public Sensor<bool> {
  public:
    LightSensor();
    virtual ~LightSensor();
    const SensorData& getData();
};

#endif // LIGHT_SENSOR_H_