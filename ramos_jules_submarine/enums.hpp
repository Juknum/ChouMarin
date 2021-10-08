/**
 * @author Jules Ramos
 * @file Scheduler.hpp
 * @date 07/10/2021
 * @brief Enumeration declaration for EType
 */

#ifndef ENUMS_HPP_
#define ENUMS_HPP_

/*
 * this enum aims at making the sensor type handling easier
 * and to enable switches (compared to a simple string which was my first solution)
 * this should make the final version of the program easier to code
 */
enum EType
{
  e_light,
  e_pression,
  e_humidity,
  e_temperature,
  e_sound
};


#endif /* ENUMS_HPP_ */
