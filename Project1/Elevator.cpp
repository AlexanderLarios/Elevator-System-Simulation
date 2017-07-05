// Elevator.cpp
// Elevator class 
#include "Elevator.h"
//cpp Pull request
Elevator::Elevator(int floors_, int defaultFloor_) 
{
	floors = floors_;
	defaultFloor = defaultFloor_;
	currentFloor = defaultFloor_;
	direction = -1;
}
int Elevator:: getDefaultFloor() {
	return defaultFloor;
}
void Elevator::called(int floor_, int direction_){
	if(direction_ == direction)
		{
			floor_Q.push(floor_);
		}
}

void Elevator::dropOff(){
	if(currentFloor == floor_Q.front()){floor_Q.pop();}
}

void Elevator::up(){
	currentFloor++;
}

void Elevator::down(){
	currentFloor--;
}

void Elevator::goToFloor(int Floor){


void Elevator ::process(){

	if(floor_Q.size() == 0) {
		if(currentFloor == defaultFloor){
			direction = 0;
		}
		else if ( currentFloor < defaultFloor) direction = 1;
		else direction = -1;
	}

	else if (floor_Q.front() == currentFloor)
	{	while (floor_Q.front() == currentFloor)
			{ dropoff();}
		}
	else {
		if(floor_Q.front() > currentFloor){
			direction = 1; up();
				}
		else {direction = -1; down()}
	}
}