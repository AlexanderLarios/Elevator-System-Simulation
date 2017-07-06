// User.h
// CS303 Project 1

#include "Elevator.h"

struct User{
public:
User(){};
User(bool dropoff, bool direction, int defaultFloor, int currentFloor);
int startFloor;
int endFloor;
int direction;
bool pickedUp;
};


