// Simulation.h 
// CS303 Project 1

#include "Simulation.h"
#include "Random.h"
#include "Passenger.h"
#include <iostream>
using namespace std;
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

bool Simulation :: spawnPassenger (){  
	randInt = randomInt();
	//50% chance to spawn a new
    if(randInt <= 50){
		//random numbers to generate starting and ending floors
		start = randomFloor(floors);
		end =randomFloor(floors);
		if (start < end) {
			direction = 1;
		}
		else {
			direction = -1;
		}
		//Call Constructor
		simPassengers.push_back(Passenger(start, end, direction));
		elevator.called(start, direction);
		return true;
    }
	return false;
}

void Simulation :: Simulate (){ 
	int turns = 0;
	while(turns < maxTurns){
		if (spawnPassenger()) {
			cout << "Passanger spawned on floor:" << start << endl;
		}

		if (elevator.process()) {
			cout << "Elevator door Opened on floor" << elevator.getCurrentFloor()<<endl;
		}
   
    //Increment the number of turns
      turns++;
   }
}

