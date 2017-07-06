#include "User.h"

User :: User(int direction_, int defaultFloor, int finalFloor){
    startFloor = defaultFloor;
    endFloor = finalFloor;
    direction = direction_;
    pickedUp = false;
}
