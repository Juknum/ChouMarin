/**
 * @author Jules Ramos
 * @file Scheduler.cpp
 * @date 21/09/2021
 * @brief Type and method definition for the Scheduler class
 */

#include "Scheduler.hpp"

Scheduler::Scheduler():m_server(),m_light(),m_temperature(),m_humidity(),m_sound(),m_pression()
{

}

Scheduler::Scheduler(const Scheduler& scheduler_p):m_server(scheduler_p.m_server),m_light(scheduler_p.m_light),
    m_temperature(scheduler_p.m_temperature),m_humidity(scheduler_p.m_humidity),m_sound(scheduler_p.m_sound),m_pression(scheduler_p.m_pression)
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

Scheduler::Scheduler(bool console_p,bool log_p):m_server(console_p,log_p),m_light(),m_temperature(),m_humidity(),m_sound(),m_pression()
{

}

template <class T> void Scheduler::SendToServer(Server& server_p, T& sensor_p)
{
  server_p.dataRcv(sensor_p.getData(), sensor_p.getSensorType());
}

void Scheduler::Launch()
{
  std::cout<<"Light: present or not\nTemperature: in °C\nHumidity: in % in the air\nSound: in dB\nPression: in hPa"<<std::endl;

  //for the first version of this program, all sensors have the same time interval of 2s; to be reworked for the final version

  //std::this_thread::sleep_for(std::chrono::milliseconds(2000));
  //TODO: make the threads work to use this line instead of the macro

  while(true)
  {
    this->SendToServer(m_server, m_light);
    this->SendToServer(m_server, m_temperature);
    this->SendToServer(m_server, m_humidity);
    this->SendToServer(m_server, m_sound);
    this->SendToServer(m_server, m_pression);

    Sleep(2000);
  }

}

//researched solutions for breaking the loop with an input:

//std::cin>>stopCheck; useless because it stops the loop

/*if (std::cin.get() == 'q')
      break; */
//same issue

//signals aren't working either, restricts to 1 instance of scheduler and couldn't get them to work
//other option: signal in main, instantly triggered so failed
//in Scheduler but with a global bool variable: fail again, ctrl+c failed too

/*
 * signal(SIGINT, signalHandler);
 * void signalHandler( int signum ) {
   std::cout << "Interrupt signal (" << signum << ") received.\n";

   loopCheck = false;

   exit(signum);
}
 * created a loopCheck.hpp file with a static bool loopCheck variable
 */


//TODO: when thread works, infinite loop breaking: see https://stackoverflow.com/questions/19966923/breaking-out-of-an-infinite-loop
/*
 * void user_input(){
    if(std::cin.get()=='n'){
        break_condition = true;
    }
}
 */
