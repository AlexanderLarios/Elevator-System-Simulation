#include <list>
#include "Elevator.h"
#include "Passenger.h"
#pragma once
class Simulation {
private:
	int turn = 0;
	int maxTurns;
	int waitTime;
	int randInt;
	int floors;
	int direction;
	int start;
	int end;
    int spawnRate;
    int totalTurns= 0;
    int PassengersDelivered =0;
    int avgWT;
	std::list<Passenger> passengers;
	Elevator elevator = Elevator(floors, 1);

public:
    Simulation(int floors_, int maxTurns_, int spawnRate_);
	void addTurns();
	int getWaitTime();
    void simulate();
    bool spawnPassenger ();

  
  
};
