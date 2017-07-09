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
   {  //Generate a new user: Needs a percent chance function!!!
    //genUser();
      User theUser = new User;
    
     //random numbers to generate starting and ending floors
      int start = random();
      int end = random();
    
    //determine direction from rand nums
    int direction_;
     if(end-start > 0) direction_ = 1;
     else direction_ = -1;
    
    //E1.call(newuser.getStartfloor, newuser.getDirection)
    //assign random numbers to the user
      theUser(direction_, start, end);
    
    //send the user info to the elevator to be processed
      Elevator.process(); 
    
    //Increment the number of turns
      turns++;
   }
}
/*
void Simulation :: Simulate ()
{  int turns = 0;
   while(turns < MaxTurns)
   {  //Generate a new user
      User theUser = new User;
    
     //random numbers to generate starting and ending floors
      int start = random();
      int end = random();
    
    //determine direction from rand nums
    int direction_;
     if(end-start > 0) direction_ = 1;
     else direction_ = -1;
    
    //assign random numbers to the user
      theUser(direction_, start, end);
    
    //send the user info to the elevator to be processed
      Elevator.process(theUser); 
    
    //Increment the number of turns
      turns++;
   }
}
