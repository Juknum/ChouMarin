/**
 * @author @Juknum (Julien CONSTANT)
 * @file HumiditySensor.hpp
 * @date 28/09/2021
 * @brief Humidity sensor class header file
 */

#ifndef HUMIDITY_SENSOR_H_
#define HUMIDITY_SENSOR_H_

#include "../../../Includes/Sensor.hpp"

class HumiditySensor: public Sensor<float> {
  public:
    HumiditySensor();
    virtual ~HumiditySensor();
    const SensorData& getData();
};

#endif // HUMIDITY_SENSOR_H_