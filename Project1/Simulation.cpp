// Simulation.h 
// CS303 Project 1

#include "Simulator.h"
#include "Random"

 void Simulation :: Simulation (int elevatorFloor_, int MaxTurns_, double Frequency_)
 {  
    elevatorFloor = elevatorFloor_;
    MaxTurns = MaxTurns_;
    Frequency = Frequency_;
 }
bool Simulation :: genuser ()
{    //Generate a new user
   if(rand() % (2)) == 0)
   {
     //random numbers to generate starting and ending floors
      int start = int(std::random()%floors);
      int end = int(std::random()%floors);
    
    //pushback user contructor into the list container
    Passengers.push_back(User(start, end));
   }
}

void Simulation :: Simulate ()
{  int turns = 0;
   while(turns < MaxTurns)
   { genuser();
    
    //send the user info to the elevator to be processed
     Elevator.process(); 
    
    //Increment the number of turns
      turns++;
   }
}

