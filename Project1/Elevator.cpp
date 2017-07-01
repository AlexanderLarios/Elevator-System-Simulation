// Elevator.cpp
// Elevator class 
#include "Elevator.h"

Elevator :: Elevator(int floors_, int defaultFloor_){
	floors = floors_;
	defaultFloor = defaultFloor_;
	currentFloor = defaultFloor_;
	direction = -1;
}

void Elevator:: Elevator floorCalled(int floor_, int direction_){
	if(direction_ == direction)
		{
			floor_Q.push(floor_);
		}

}

void Elevator:: Elevator dropoff(){
	if(currentFloor == floor_Q.front()){floor_Q.pop();}
}

void Elevator:: Elevator  up(){
	currentFloor++;
}

void Elevator:: Elevator  down(){
	currentFloor--;
}

void Elevator:: Elevator goto(int Floor){

	if(buttonCalls.empty()) {
		return;
	}  

  if (show) {
   cout << "The elevator has made its PICKUP" << endl;
  }
}

void Elevator :: Elevator process(){

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