#include "User.h"

User :: User(int defaultFloor, int finalFloor, int direction_){
    startFloor = defaultFloor;
    endFloor = finalFloor;
    pickedUp = false;
    direction = direction_;
    
}
//User :: ~User(){};

int User:: waiting_time;

