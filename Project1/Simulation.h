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
private:
  int clock;
  Elevator elevator;
  std::list<User> simPassangers;
  
}
