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

//called by sim interface. adds pick up request to directional vector
void Elevator::called(int floor_, int direction_){
	if(direction_ ==1){
		upList.push_back(floor_);
		}
	else if (direction_ ==-1){
		downList.push_back(floor_);
		}

}

//if floor is destination it pops the int floor from list and sends Open door /Drop off to sim
bool Elevator::dropOff(){
	if (direction == 1 && currentFloor == upList.back){
		upList.pop_back;
		
		return true;
	}
	else if (direction == -1 && currentFloor == downList.back) {
		downList.pop_back;
		
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
		upList.push_back(floor_);
	}
	else {
		downList.push_back(floor_);
	}
}
//allows sims to get out. have not created them yet though.
void Elevator::open() {
	
}
//Checks to see if Uk > 0 for upList and inverse for Down List
bool Elevator::checkUkUp(list<int>& upList_) {
	for (list<int>::iterator it = upList_.begin(); it != upList_.end(); ++it) {
		if (*it > currentFloor) {
			return true;
		}
	}
	return false;
	
}

bool Elevator::checkUkDown(list<int>& downList_) {
	for (list<int>::iterator it = downList_.begin(); it != downList_.end(); ++it) {
		if (*it < currentFloor) {
			return true;
		}
	}
	return false;

}
// logic run by elevator when it reaches a new floor or when released from idle
void Elevator::process(){
	//If the elevator is idle return it to its default floor
	if(upList.empty() && downList.empty()) {
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
		if(!upList.empty()&& direction ==1){
			moveUp();
		}
		else if (!downList.empty() && direction == -1) {
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