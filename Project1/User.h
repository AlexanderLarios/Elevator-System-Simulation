#include "elevator.h"

struct User{
public:
User(){};
User(int direction_, int defaultFloor, int finalFloor);
int defaultFloor;
int finalFloor;
int direction;
bool pickedUp;
};


