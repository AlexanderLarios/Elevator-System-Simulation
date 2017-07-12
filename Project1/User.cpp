#include "User.h"
//Constructor
User::User(int defaultFloor, int finalFloor, int direction_){
    startFloor = defaultFloor;
    endFloor = finalFloor;
    pickedUp = false;
    direction = direction_;
    }

//Setters
void User::setWT(int wt){
    waitingTime = wt;
    }

//Getters
int User::getWT(){
    return waitingTime;
}

int User::getStartFloor(){
    return startFloor;
}

int User::getEndFloor(){
    return endFloor;
}

int User::getDirection(){
    return direction;
}
