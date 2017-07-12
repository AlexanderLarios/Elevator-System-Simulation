#include "Passenger.h"
//Constructor
Passenger::Passenger(int startFloor_, int endFloor_, int direction_){
    startFloor = startFloor_;
    endFloor = endFloor_;
    pickedUp = false;
    direction = direction_;
    }

//Setters
void Passenger::setWT(int wt){
    waitingTime = wt;
    }

//Getters
int Passenger::getWT(){
    return waitingTime;
}

int Passenger::getStartFloor(){
    return startFloor;
}

int Passenger::getEndFloor(){
    return endFloor;
}

int Passenger::getDirection(){
    return direction;
}
