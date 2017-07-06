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

void Simulation :: Simulate ()
{  int turns = 0;
   while(turns < MaxTurns)
   {  //random number to generate a new user
      New User();
     
     //random numbers to generate starting and ending floors
      int start;
      int end;
      
    
     
      Elevator.process(); 
       turns++;
   }
}
