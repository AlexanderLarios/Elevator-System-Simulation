#include <list>
#include "Elevator.h"
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
	Elevator elevator = Elevator(floors, 1);
	std::list<class Passenger> passengers;
	std::list<class Passenger>::iterator it;
public:
    Simulation(int floors_, int MaxTurns_, double Frequency_);
	void addTurns();
	int getWaitTime();
    void simulate();
    bool spawnPassenger ();

  
  
};
