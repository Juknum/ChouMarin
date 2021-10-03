/**
 * @author Jules Ramos
 * @file main.cpp
 * @date 22/09/2021
 * @brief file for the main function
 */

#include "Scheduler.hpp"
#include "Server.hpp"
#include <iostream>

int main()
{
  float data = 12;
  std::cout<<"start\n"<<"data = "<<data<<std::endl;
  std::cout<<"test completed"<<std::endl;

  Server serv;
  serv.dataRcv(5, "test");
}

//300m!!! de profondeur
