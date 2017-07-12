#include <list>
#include "User.h"
#pragma once
class Simulation {
private:
	int MaxTurn;
    int clock;
	int waitTime;
	int randomInt;
    double Frequency;
    std::list<User> simPassengers;
   
public:
    Simulation(int elevatorFloor_, int MaxTurns_, double Frequency_);
	int getWaitTime();
    void Simulate();
    bool genUser ();
  
  
};
