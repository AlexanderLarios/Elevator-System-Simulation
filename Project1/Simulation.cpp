// Simulation.h 
// CS303 Project 1

#include "Simulation.h"
#include "Random.h"
#include "Passenger.h"


//Constructor
Simulation::Simulation(int floors_ , int MaxTurns_, double Frequency_)
 {  
    floors = floors_;
    maxTurns = MaxTurns_;
    Frequency = Frequency_;
 }

int Simulation::getWaitTime() {
	return waitTime;
}

bool Simulation :: spawnPassenger ()
{  //50% chance to spawn a new
	randInt = randomInt();
    if(randInt <= 50){
		//random numbers to generate starting and ending floors
		int start = randomFloor(floors);
		int end =randomFloor(floors);
		if (start < end) {
			direction = 1;
		}
		else {
			direction = -1;
		}
		//Call Constructor
		simPassengers.push_back(Passanger(start, end, direction));
    }
   
     

    //pushback user contructor into the list container
    simPassengers.push_back(Passenger(start, end, direction));
    Elevator.called(start, direction);
   
}

void Simulation :: Simulate ()
{  int turns = 0;
   while(turns < MaxTurns){
       if genuser();
     if Elevator.process()
    
    //Increment the number of turns
      turns++;
   }
}

