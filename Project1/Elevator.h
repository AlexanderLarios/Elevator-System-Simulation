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
	void called();
	void SetDefaultFloor(int defaultFloor_);
	void process();
	void gotoFloor(bool show_all);
	int getDefaultFloor()

};
//Add definitions here
