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
      User theUser = new User;
    
     
     //random numbers to generate starting and ending floors
      int start;
      int end;
      
    //assign random numbers to the user
      theUser(int direction_, int defaultFloor, int finalFloor);
    
    //send the user info to the elevator to be processed
      Elevator.process(theUser); 
       turns++;
   }
}
