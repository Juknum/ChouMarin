/**
 * @author @Juknum (Julien CONSTANT)
 * @file Sensor.hpp
 * @date 27/09/2021
 * @brief Sensor class header file
 */

#ifndef SENSOR_H_
#define SENSOR_H_

#include <cmath>
#include "constants.hpp"

class SensorBase {
  protected:
    SensorData data; // data of the sensor

    /**
     * @brief Random number generator between [min, max] with a precision value for floats
     * @tparam T type of the variable
     * @param min first number possible
     * @param max last number possible
     * @param precision number of decimal (float only)
     * @return T random number in [min, max]
     */
    template<typename T> T aleaGenVal(T min = -1, T max = -1, unsigned int precision = 0) {
      if (min == max && min > -1) return min;         // rand in [min, min]
      if (min > -1 && max == -1) return rand() + min; // rand in [min, inf[
      if (min < 0) return rand();                     // rand in [0, inf[

      // determine decimal length
      unsigned int power = 1;
      if (precision > 0) for (unsigned int i = 0; i < precision; i++) power *= 10;

      // get random integer part + random decimal part (if precision is > 0)
      return (T)((std::fmod(rand(), max - min - 1.0) + min) + ((precision > 0) ? aleaGenVal<float>(0, (int)power) / (float)power : 0.0));
};

public:
  SensorBase();
  SensorBase(SensorType sT, DataType dT);

  virtual ~SensorBase();
  virtual const SensorData& getData() = 0; // default value set to 0
};

// template for all existing sensors
template <class T> class Sensor: public SensorBase {
  protected:
    T value;
  public:
    Sensor<T>();
    Sensor<T>(SensorType sT, DataType dT): SensorBase(sT, dT), value() {};

    virtual ~Sensor() {};
    virtual const SensorData& getData() = 0;
};

#endif // SENSOR_H_
