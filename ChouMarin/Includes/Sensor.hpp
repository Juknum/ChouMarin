/**
 * @author @Juknum (Julien CONSTANT)
 * @file Sensor.hpp
 * @date 27/09/2021
 * @brief Sensor class header file
 */

#ifndef SENSOR_H_
#define SENSOR_H_

#include "Constants.hpp"

class SensorBase {
protected:
  SensorData data;      // data of the sensor
  void emptyValue();    // delete data properly
public:
  SensorBase();
  SensorBase(SensorType sT, DataType dT);
  SensorBase(const SensorBase& sB);
  SensorBase& operator=(const SensorBase &sB);

  virtual ~SensorBase();
  virtual const SensorData& sendData() = 0;
};

// template for all existing sensors
template <class T> class Sensor: public SensorBase {
protected:
  T value;
public:
  Sensor<T>();
  Sensor<T>(SensorType sT, DataType dT): SensorBase(sT, dT), value() {};
  Sensor<T>(const Sensor<T>& s): SensorBase(s), value(s.value) {};
  Sensor<T>& operator=(Sensor<T> const& s) { this->value = s.value; return *this; }

  virtual ~Sensor() {};
  virtual const SensorData& sendData() = 0;
};

#endif // SENSOR_H_
