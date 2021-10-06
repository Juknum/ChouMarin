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
#include <string>

/**
 * @brief small loop to choose some boolean options to configure the program
 * @return bool: user choice
 * @param: none
 */
bool boolChoose()
{
  std::string input;

  do
  {
    std::cin>>input;

    if (input == "y" || input == "Y")
    {
      return true;
    }
    else if (input == "n" || input == "N")
    {
      return false;
    }
    else
    {
      std::cout<<"Please choose Y or N!"<<std::endl;
    }
  } while (!(input == "y" || input == "Y" || input == "n" || input == "N"));

  return false; //just so that the compiler is happy
}

/**
 * @brief main function, start of the program
 * @return int: EXIT_SUCCESS to be cross platform
 * @param none
 */
int main()
{
  bool log,console;
  //Scheduler schedul;

  srand (time(NULL));
  std::cout<<"Starting the submarine."<<std::endl;

  std::cout<<"Do you want to write in log files?"<<std::endl;
  log=boolChoose();

  std::cout<<"Do you want to write in the console?"<<std::endl;
  console=boolChoose();

  if (!(log == false && console == false))
  {
    Scheduler schedul(console,log);
    schedul.Launch();
  }

  return EXIT_SUCCESS;
}

//300m!!! de profondeur
