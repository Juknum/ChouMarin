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