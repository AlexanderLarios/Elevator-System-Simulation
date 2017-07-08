#include "Elevator.h"
#include <iostream>

using namespace std;

class Simulation 
{
public:
  
  Simulation() :clock(0) {}
  
  int elevatorFloor;
  int MaxTurn;
  double Frequency;

 void Simulation :: Simulation (int elevatorFloor, int MaxTurns, double Frequency);
  
private:
  int clock;
  Elevator elevator;
}
