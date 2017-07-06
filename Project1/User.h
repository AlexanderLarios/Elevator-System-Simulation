#include "elevator.h"

struct User{
public:
User(){};
User(bool dropoff, bool direction, int defaultFloor, int currentFloor);
int levels;
int currentFloor;
int direction;
int defaultFloor;
bool pickedUp;
};


