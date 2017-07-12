#include <list>
#include "Elevator.h"
#pragma once
class Simulation {
private:
	int Turn = 0;
	int maxTurns;
    int clock;
	int waitTime;
	int randInt;
	int floors;
	int direction;
	int start;
	int end;
    double Frequency;
	Elevator elevator = Elevator(floors, 1);
    std::list<Passenger> simPassengers;
   
public:
    Simulation(int elevatorFloor_, int MaxTurns_, double Frequency_);
	int getWaitTime();
    void Simulate();
    bool spawnPassenger ();
  
  
};
