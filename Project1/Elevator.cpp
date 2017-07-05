// Elevator.cpp
// Elevator class 
// Define that.
#include "Elevator.h"
//constructor
Elevator::Elevator(int floors_, int defaultFloor_) 
{
	floors = floors_;
	defaultFloor = defaultFloor_;
	currentFloor = defaultFloor_;
	direction = -1;
}
//Change default floor
void Elevator::SetDefaultFloor(int defaultFloor_) {
	defaultFloor = defaultFloor_;
}
//returns default floor of elevator
int Elevator:: getDefaultFloor() {
	return defaultFloor;
}
//returns current floor of elevator
int Elevator::getCurrentFloor() {
	return currentFloor;
}

//returns current elevator direction -1 down, 0 idle , 1 up ;)
int Elevator::getDirection() {
	return direction;
}
//overides direction of elevator
int Elevator::setDirection(int direction_) {
	direction = direction_;
}

//Set number of destinations. Choose 1 for up, 0 for down.
void Elevator::setVectorCount(bool direction_, int VectorCount_) {
	if (direction_) {
		vectorCountUp = VectorCount_;
	}
	else {
		vectorCountDown = VectorCount_;
	}
}
//get number of destinations in vector. Choose 1 for up, 0 for down.
int Elevator::getVectorCount(bool direction_) {
	if (direction_) {
		return vectorCountUp;
	}
	else {
		return vectorCountDown;
	}
}
//called by sim interface. adds pick up request to directional vector
void Elevator::called(int floor_, int direction_){
	if(direction_ ==1){
		upVector.push_back(floor_);
		}
	else if (direction_ ==-1){
		downVector.push_back(floor_);
		}

}

//if floor is destination it pops floor from vector and sends Open door /Drop off to sim
//This function requires sorted vectors to function properly*****
bool Elevator::dropOff(){
	if (direction == 1 && currentFloor == upVector.back){
		upVector.pop_back;
		
		return true;
	}
	else if (direction == -1 && currentFloor == downVector.back) {
		downVector.pop_back;
		
		return true;
	}
	else 
		return false;
}

//Moves elevator up or down a floor by altering current floor and moving in that floors direction
void Elevator::moveUp(){
	currentFloor++;
	direction = 1;
}
void Elevator::moveDown(){
	currentFloor--;
	direction = -1;
}
//add floor as a destination accessed by sim interface inside car.
void Elevator::goToFloor(int floor_) {
	if (floor_ > currentFloor) {
		upVector.push_back(floor_);
	}
	else {
		downVector.push_back(floor_);
	}
}
void Elevator::open() {
	//allows sims to get out. have not created them yet though.
}
// logic run by elevator when it reaches a new floor or when released from idle
void Elevator::process(){
	//If the elevator is idle return it to its default floor
	if(upVector.empty() && downVector.empty()) {
		if(currentFloor == defaultFloor){
			direction = 0;
		}
		else if (currentFloor < defaultFloor) {
			direction = 1;
			moveUp();
		}
		else {
			direction = -1;
			moveDown();
		}
	}
	//checks to see if the current floor is a destination from appropriate vector.
	else if (dropOff()) {
		//call open for sims to get off
		open();
	}
	else {
		if(!upVector.empty()&& direction ==1){
			moveUp();
		}
		else if (!downVector.empty() && direction == -1) {
			moveDown();
		}
		else{
			if (direction == -1) {
				moveUp();
			}
			else {
				moveDown();
			}
		}
	}
}