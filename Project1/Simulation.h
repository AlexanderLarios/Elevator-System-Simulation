#include <list>
#include "User.h"
#pragma once
class Simulation {
private:
    int clock;
    int arrival_time;
    int waiting_time; //max_processing_time in simulator
    int my_random;
    double Frequency;
    std::list<User> simPassengers;
   
public:
    Simulation(int elevatorFloor_, int MaxTurns_, double Frequency_);
    int elevatorFloor;
    int MaxTurn;
    int waitTime;
    int get_arrival_time (){ return arrival_time;}
    int get_waiting_time (){ return waiting_time;}
    void Simulate();
    bool genuser ();
  
  
};
