#include <list>
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
    double Frequency;
    std::list<Passenger> simPassengers;
   
public:
    Simulation(int elevatorFloor_, int MaxTurns_, double Frequency_);
	int getWaitTime();
    void Simulate();
    bool spawnPassenger ();
  
  
};
