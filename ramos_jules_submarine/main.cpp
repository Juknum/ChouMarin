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

//LITTLE SUMMARY OF WHAT I DID AND WASN'T ABLE TO DO AT THE END OF THIS FILE

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

/*
 * All of the first version objectives were respected. I didn't manage to make threads work
 * and hence had to use an alternative to this_thread::sleep_for with a macro to make this program cross platform
 * I also wanted to find a way to stop the loop with an input so that the program would run ad vitam eternam EXCEPT
 * if the user stopped it but I didn't manage to find a solution, neither threads nor signals nor buffer checking solutions
 *  worked and this will be one of my objectives for the final version.
 * I managed to give the user the choice to write in log files, in the console or in both (or in neither of them but
 * the program just stops then) and to handle the sensors with an abstract class and an inheritance coupled with an enum.
 * Overall I'm satisfied with this first version of the project even though I didn't manage to program everything I would have
 * liked to.
 * For the final version of this project, I'll also need to take a look at possible memory leaks as the program is currently
 * forced stop which isn't ideal.
 * I'll also try to use the random library for a better random number generation, and make it so that
 * the values don't vary too much in a few seconds (to avoid the submarine going from 15°C to 25°C in 2s).
 * I payed attention to code in a way that would allow me to easily make changes for the final version of
 * the project and in that way I am satisfied with what I did.
 */
