//Elevator.h

#include Simulation.h
#include User Interface.h
//github test
#pragma once

//Elevator class header.
class Elevator {
public:
Elevator() {}

Elevator(int floors_, int defaultFloor_);
floorCalled(), direction(1)
currentFloor(0),
defaultFloor(floors), 
process();

// This is used to go up and down the current/default floor
void defaultFloor(bool pickUp, bool show) {
if (up) {
currentFloor++;
}
else {
currentFLoor--;
direction = up;
if(show) {
currentFLoor;
}
}
 
//This moves the elevator  in the desired direction when the user pressed the button for the desired floor
void gotoFloor(bool show_all);
 int getdefaultFloor() {
  return defaultFloor;
}
 
 private: 
 int currentFloor;
 int que_count;
 int direction;
 int floors;
 int defaultFloor;
 queue <int> floor_Q;
 }
 
//Add definitions here
