/**
 * @author Jules Ramos
 * @file Server.cpp
 * @date 22/09/2021
 * @brief Type and method definition for the Sound class
 */

#include "Sound.hpp"

Sound::Sound()
{
  m_sensorType="sound";
};

Sound::Sound(const Sound& sound_p)
{
  m_sensorType = sound_p.m_sensorType;
};

Sound::~Sound(){};

void Sound::operator=(const Sound& sound_p)
{
  this->m_sensorType = sound_p.m_sensorType;
};

float Sound::aleaGenVal()
{
  return rand()%100; //from 0 to 99, placeholder, to be reworked after the inheritance
}

float Sound::getData()
{
  return this->aleaGenVal();
}
