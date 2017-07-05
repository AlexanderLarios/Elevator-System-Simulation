//Elevator.h
//Elevator class header.
#pragma once

class Elevator {
	
private:
	int currentFloor;
	int que_count;
	int direction;
	int floors;
	int defaultFloor;
	


public:
	Elevator(int floors_, int defaultFloor_);
	void called(int floor_, int direction_);
	void SetDefaultFloor(int defaultFloor_);
	void dropOff();
	void process();
	void goToFloor(int floor_);
	void up();
	void down();
	int getDefaultFloor();

};
