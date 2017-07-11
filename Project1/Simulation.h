//Also, similar to passenger for airline simulation
#include "Elevator.h"
#include "User.h"
#include <iostream>

using namespace std;

class Simulation 
{
public:
  
  Simulation() :clock(0) {}
  
  int elevatorFloor;
  int MaxTurn;
  double Frequency;
  int waitTime;

 void Simulation :: Simulation (int elevatorFloor, int MaxTurns, double Frequency);
 bool Simulation :: genuser ();
 int get_arrival_time (){ return arrival_time;}
 int get_waiting_time (){ return waiting_time;}
  
  
private:
  int clock;
  int arrival_time;
  int waiting_time; //max_processing_time in simulator
  
  Elevator elevator;
  std::list<User> simPassengers;
  
}
