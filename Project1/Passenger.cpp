#include "Passenger.h"
//Constructor
User::User(int startFloor_, int endFloor_, int direction_){
    startFloor = startFloor_;
    endFloor = endFloor_;
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
