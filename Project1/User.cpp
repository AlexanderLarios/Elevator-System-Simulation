#include "User.h"

User :: User(int defaultFloor, int finalFloor, int direction_){
    startFloor = defaultFloor;
    endFloor = finalFloor;
    pickedUp = false;
    direction = direction_;
    }

void User:: setWT(int wt){
    waitingTime = wt;
}

