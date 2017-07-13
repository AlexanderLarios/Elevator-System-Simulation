//Elevator.h
//Elevator class header.
//Declare that.
#pragma once
#include <list>
class Elevator {
	
private:
	//Lists for up and down
    std::list<int> upList;
    std::list<int> downList;
	std::list<int> eQueue;
    // more members
	int defaultFloor=1;
	int currentFloor=1;
	int direction=0;
	int floors;

public:
	
	//constructor
	Elevator(int floors_, int defaultFloor_);
	
	//function that is called by the outer interface by sim
	void called(int floor_, int callDirection);
	
	//returns default floor of elevator
	int getDefaultFloor();
	
	//returns current floor of elevator
	int getCurrentFloor();
	
	//returns current elevator direction -1 down, 0 idle , 1 up ;)
	int getDirection();
	
	//overides direction of elevator
	void setDirection(int direction_);
	
	//Change default floor
	void SetDefaultFloor(int defaultFloor_);
	
	//called to check if floor is a destination
	bool dropOff();
	
	// logic run by elevator when it reaches a new floor or when released from idle
	bool process();
	
	//add floor as a destination
	void goToFloor(int floor_);
	
	//Moves elevator up a floor
	void moveUp();
	
	//Moves elevator down a floor
	void moveDown();
	
	//
	void checkUkUp();
    
	void checkUkDown();
    
	void queuePushUp();
	void queuePushDown();
	

};
