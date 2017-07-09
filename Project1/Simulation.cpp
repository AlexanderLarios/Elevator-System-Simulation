// Simulation.h 
// CS303 Project 1

#include "Simulator.h"
#include "Random"
/*
int timeWaited(){

}
*/
/*
//
newFunction(){
  currentFloor = E1.getcurrentFloor;
  direction = E1.getDirection;
  if(open() == true && pickup()== true && direction == 1)
  {
    for (list<int>::iterator it = upList_.begin(); it != upList_.end(); ++it) {
		if (*it > currentFloor) {
			return true;
		}
	}
  }
  else if(open() == true && pickup()== true && direction == -1)
  {
    for (list<int>::iterator it = upList_.begin(); it != upList_.end(); ++it) {
		if (*it > currentFloor) {
			return true;
		}
	}
  }
  
  
}
*/
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
      if(start < end){
        direction = 1 ;
       }
    else {
        direction = -1;
         }
    
    //pushback user contructor into the list container
    Passengers.push_back(User(start, end, direction));
    
    //
    Elevator.called(start, direction);
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

