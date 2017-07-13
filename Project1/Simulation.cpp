// Simulation.h 
// CS303 Project 1

#include "Simulation.h"
#include "Random.h"
#include "Passenger.h"
#include <iostream>
using namespace std;
//Constructor
Simulation::Simulation(int floors_, int maxTurns_, int spawnRate_)
 {  
    floors = floors_;
    maxTurns = maxTurns_;
    spawnRate = spawnRate_;
 }

int Simulation::getWaitTime() {
	return waitTime;
}

bool Simulation :: spawnPassenger (){  
	randInt = randomInt();
	//spawnRate% chance to spawn a new passenger
    if(randInt <= spawnRate){
		//random numbers to generate starting and ending floors
		start = randomFloor(floors);
		end =randomFloor(floors);
		while (start == end) {
			end = randomFloor(floors);
		}
		if (start < end) {
			direction = 1;
		}
		else {
			direction = -1;
		}
		//Call Constructor
		passengers.push_back(Passenger(start, end, direction));
		elevator.called(start, direction);
		return true;
    }
	return false;
}

//increments all passangers turns by 1

void Simulation::addTurns() {
    if (!passengers.empty()){
        for (std::list<Passenger>::iterator it= passengers.begin(); it != passengers.end(); ++it){
            Passenger psg = *it;
            psg.addTurn();
        }
    }
}

void Simulation::simulate(){ 
	turn = 1;
	while(turn < maxTurns){
		cout << "Turn #" << turn << endl;
		if (spawnPassenger()) {
			cout << "Passanger spawned on floor:" << start << "Destination:" << end<< endl;
		}

		if (elevator.process()) {
			cout << "Elevator door Opened on floor" << elevator.getCurrentFloor()<<endl;
            if (!passengers.empty()){
                for (std::list<Passenger>::iterator it= passengers.begin(); it != passengers.end(); ++it){
                    Passenger psg = *it;
                    if (psg.getPickedUp()){
                        if(psg.getEndFloor() == elevator.getCurrentFloor()){
                            psg.getTurns()
                            
                        }
                        
                    }
                }
            }

		}
   
		//Increment the number of turns for sim and for passangers
		addTurns();
		turn++;

   }
	cout << "Total Turns:" << turn << endl;
	cout << "Average Wait Time:" << endl;
}

