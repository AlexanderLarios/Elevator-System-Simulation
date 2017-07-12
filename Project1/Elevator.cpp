// Elevator.cpp
// Elevator class 
// Define that.
#include "Elevator.h"
#include <iterator>
#include <iostream>
using namespace std;
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
void Elevator::setDirection(int direction_) {
	direction = direction_;
}
//called by sim interface. adds pick up request to directional vector
void Elevator::called(int floor_, int direction_){
	//add floor to proper list
	if(direction_ ==1){
		upList.push_back(floor_);
		}
	else if (direction_ ==-1){
		downList.push_back(floor_);
		}

}
bool Elevator::checkFloor(){
	if (direction == 1) {
		for (list<int>::iterator it = upList.begin(); it != upList.end(); ++it) {
			if (*it == currentFloor) {
				return true;
			}
		}
	}
	else if (direction == -1){
		for (list<int>::iterator it = downList.begin(); it != downList.end(); ++it) {
			if (*it == currentFloor) {
				return true;
			}
		}
	}
	return false;

}

//if floor is destination it pops the int floor from list and sends Open door /Drop off to sim
bool Elevator::dropOff(){
	if (direction == 1 ){
		list<int>::iterator it = upList.begin();
		while (it != upList.end()) {
		if ((*it) == currentFloor) {
			it = upList.erase(it);
			return true;
		}
		else
			it++;
		}
		return false;
		
	}
	else if (direction == -1) {
		list<int>::iterator it = downList.begin();
		while (it != downList.end()) {
			if ((*it) == currentFloor) {
				it = downList.erase(it);
				return true;
			}
			else
				it++;
		}
		return false;
	}
	else
		return false;
}

//Moves elevator up or down a floor by altering current floor and moving in that floors direction
void Elevator::moveUp(){
	currentFloor++;
	direction = 1;
	cout << "Elevator Moved up to floor" << currentFloor << endl;
}
void Elevator::moveDown(){
	currentFloor--;
	direction = -1;
	cout << "Elevator Moved down to floor" << currentFloor << endl;
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

//Checks to see if Uk > 0 for upList
bool Elevator::checkUkUp() {
	for (list<int>::iterator it = upList.begin(); it != upList.end(); ++it) {
		if (*it > currentFloor) {
			return true;
		}
	}
	return false;
	
}
//Checks to see if Uk < 0 for Down List
bool Elevator::checkUkDown() {
	for (list<int>::iterator it = downList.begin(); it != downList.end(); ++it) {
		if (*it < currentFloor) {
			return true;
		}
	}
	return false;

}
//allows sims to get out. have not created them yet though.
int Elevator::open() {
    return true;
}
// logic run by elevator when it reaches a new floor or when released from idle
bool Elevator::process(){
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
		return false;
	}
	//checks to see if the current floor is in the direction lists.
	else if (dropOff()) {
		//return true so the simulation knows to check passangers
		open();
	}
	else {
        if(direction == 1 && this->checkUkUp() ==true){
			moveUp();
		}
		else if (direction == -1 && this->checkUkDown() == true) {
			moveDown();
		}
		else if (direction == 0) {
			if (this->checkUkUp() == true) {
				moveUp();
			}
			if (this->checkUkDown() == true) {
				moveDown();
			}
		}
		else{
			if (direction == -1) {
				moveUp();
			}
			else {
				moveDown();
			}
		}
		return false;
	}
}
