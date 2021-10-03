/**
 * @author Jules Ramos
 * @file Scheduler.cpp
 * @date 21/09/2021
 * @brief Type and method definition for the Scheduler class
 */

#include "Scheduler.hpp"

Scheduler::Scheduler():m_server(),m_light(),m_pression(),m_humidity(),m_sound(),m_temperature()
{

}

Scheduler::Scheduler(const Scheduler& scheduler_p):m_server(scheduler_p.m_server),m_light(scheduler_p.m_light),
    m_pression(scheduler_p.m_pression),m_humidity(scheduler_p.m_humidity),m_sound(scheduler_p.m_sound),m_temperature(scheduler_p.m_temperature)
{

}

Scheduler::~Scheduler()
{

}

void Scheduler::operator=(const Scheduler& scheduler_p)
{
  this->m_server=scheduler_p.m_server;
  this->m_sound=scheduler_p.m_sound;
  this->m_temperature=scheduler_p.m_temperature;
  this->m_light=scheduler_p.m_light;
  this->m_humidity=scheduler_p.m_humidity;
  this->m_pression=scheduler_p.m_pression;
}

Scheduler::Scheduler(bool console_p,bool log_p):m_server(console_p,log_p),m_light(),m_pression(),m_humidity(),m_sound(),m_temperature()
{

}

void Scheduler::Launch()
{
  //for the first version of this program, all sensors have the same time interval of 2s; to be reworked for the final version

}
