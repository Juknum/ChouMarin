/**
 * @author Jules Ramos
 * @file main.cpp
 * @date 22/09/2021
 * @brief file for the main function
 */

#include "Scheduler.hpp"
#include "Server.hpp"
#include <iostream>
#include <ctime>

int main()
{

  srand (time(NULL));
  std::cout<<"start"<<std::endl;

  Scheduler schedul;
  schedul.Launch();

  std::cout<<"test completed"<<std::endl;
}

//300m!!! de profondeur
