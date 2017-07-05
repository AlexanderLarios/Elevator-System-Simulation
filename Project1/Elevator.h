//Elevator.h
//Elevator class header.
//Declare that.
#pragma once
#include <vector>
class Elevator {
	
private:
	//vectors for up and down
	std::vector<int> upVector;
	std::vector<int> downVector;
	// more members
	int defaultFloor=1;
	int currentFloor=1;
	int vectorCountUp=0;
	int vectorCountDown=0;
	int direction=0;
	int floors;
	


public:
	
	//constructor
	Elevator(int floors_, int defaultFloor_);
	//function that is called by the outer interface by sim
	void called(int floor_, int direction_);
	//returns default floor of elevator
	int getDefaultFloor();
	//returns current floor of elevator
	int getCurrentFloor();
	//returns current elevator direction -1 down, 0 idle , 1 up ;)
	int getDirection();
	//overides direction of elevator
	int setDirection(int direction_);
	//Change default floor
	void SetDefaultFloor(int defaultFloor_);
	//Set number of destinations. Choose 1 for up, 0 for down.
	void setVectorCount(bool direction_, int VectorCount_);
	//get number of destinations in vector. Choose 1 for up, 0 for down.
	int getVectorCount(bool direction_);
	//called to check if floor is a destination
	bool dropOff();
	// logic run by elevator when it reaches a new floor or when released from idle
	void process();
	//add floor as a destination
	void goToFloor(int floor_);
	//Moves elevator up a floor
	void moveUp();
	//Moves elevator down a floor
	void moveDown();
	void open();


};
