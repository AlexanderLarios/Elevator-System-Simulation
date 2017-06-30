//Elevator.h

#include Simulation.h
#include User Interface.h

#pragma once

//Elevator class header.
class Elevator {
public:
Elevator() {}

Elevator(int floors):
floorCalled(), direction(1)
currentFloor(0),
defaultFloor(floors), 
 
//This moves the elevator  in the dsired direction when the user pressed the button for the desired floor
void gotoFloor(bool show_all) {
if(buttonCalls.empty()) {
return;
}  


  if (show) {
   cout << "The elevator has made its PICKUP" << endl;
  }
}
 int getdefaultFloor() {
  return defaultFloor;
}
 
 private: 
 int currentFloor;
 bool direction;
 int levels;
 int defaultFloor1;
 int defaultFloor2;
 int defaultFloor3;
 
//Add definitions here
