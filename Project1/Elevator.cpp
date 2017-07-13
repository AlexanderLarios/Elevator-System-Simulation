// Elevator.cpp
// Elevator class 
// Define that.
#include "Elevator.h"
#include <iterator>
#include <iostream>
#include <functional>
using namespace std;
//constructor
Elevator::Elevator(int floors_, int defaultFloor_) 
{
	floors = floors_;
	defaultFloor = defaultFloor_;
	currentFloor = defaultFloor_;
	direction = 1;
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
void Elevator::called(int floor_, int callDirection){
	//add floor to proper list
	if (callDirection == 1) {
		upList.push_back(floor_);
		if (callDirection == direction) {
			checkUkUp();
		}
	}
	else if (callDirection ==-1){
		downList.push_back(floor_);
			if (callDirection == direction) {
				checkUkDown();
			}
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
bool Elevator::dropOff() {
	if (currentFloor == eQueue.front()) {
		eQueue.pop_front();
		return true;
	}
	else {
		return false;
	}
}

//Moves elevator up or down a floor by altering current floor and moving in that floors direction
void Elevator::moveUp(){
	currentFloor++;
	cout << "Elevator Moved up to floor" << currentFloor << endl;
}
void Elevator::moveDown(){
	currentFloor--;
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
void Elevator::checkUkUp() {
	for (list<int>::iterator it = upList.begin(); it != upList.end(); ++it) {
		if (*it >= currentFloor) {
			eQueue.push_back(*it);
			eQueue.sort();
			upList.remove(*it);
		}
	}	
}
//Checks to see if Uk < 0 for Down List
void Elevator::checkUkDown() {
	for (list<int>::iterator it = downList.begin(); it != downList.end(); ++it) {
		if (*it <= currentFloor) {
			eQueue.push_back(*it);
			eQueue.sort(std::greater<int>());
			downList.remove(*it);	
		}
	}
}
//allows sims to get out. have not created them yet though.
int Elevator::open() {
    return true;
}
// logic run by elevator when it reaches a new floor or when released from idle
bool Elevator::process(){
	//If the elevator is idle return it to its default floor
	if(upList.empty() && downList.empty() && eQueue.empty()) {
		if(currentFloor == defaultFloor){
			direction = 0;
			cout << "Elevator Idle" << endl;
		}
		else if (currentFloor < defaultFloor) {
			direction = 0;
			moveUp();
			cout << "Elevator Idle returning to default floor" << endl;
		}
		else {
			direction = 0;
			moveDown();
			cout << "Elevator Idle returning to default floor" << endl;
		}
		return false;
	}
	else if (eQueue.empty()) {
		if (direction == 1) {
			direction == -1;
			checkUkDown();
		}
		else if (direction == -1) {
			direction == 1;
			checkUkUp;
		}

	}
	//checks to see if the current floor is a destination.
	else if (dropOff()) {
		//return true so the simulation knows to check passangers
		open();
	}
	//Movement Phase
	
	else {
        if(eQueue.front() > currentFloor){
			direction = 1;
			moveUp();
		}
		else if (eQueue.front() < currentFloor) {
			direction = -1;
			moveDown();
		}	
		return false;
	}
}
