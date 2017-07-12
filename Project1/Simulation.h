#include <list>
#include "User.h"
#pragma once
class Simulation {
private:
	int Turn = 0;
	int maxTurns;
    int clock;
	int waitTime;
	int randomInt;
	int floors;
    double Frequency;
    std::list<User> simPassengers;
   
public:
    Simulation(int elevatorFloor_, int MaxTurns_, double Frequency_);
	int getWaitTime();
    void Simulate();
    bool spawnPassenger ();
  
  
};
