/**
 * @author Jules Ramos
 * @file Server.cpp
 * @date 22/09/2021
 * @brief Type and method definition for the Sound class
 */

#include "Sound.hpp"

Sound::Sound()
{
  this->m_sensorType="sound";
};

Sound::Sound(const Sound& sound_p)
{
  this->m_sensorType = sound_p.m_sensorType;
};

Sound::~Sound(){};

void Sound::operator=(const Sound& sound_p)
{
  this->m_sensorType = sound_p.m_sensorType;
};

float Sound::aleaGenVal()
{
  return rand()%30 + 55; //from 55 to 84 dB, will stay an integer
}

float Sound::getData()
{
  return this->aleaGenVal();
}
