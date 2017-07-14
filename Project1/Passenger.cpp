#include "Passenger.h"
//Constructor
Passenger::Passenger(int startFloor_, int endFloor_, int direction_){
    startFloor = startFloor_;
    endFloor = endFloor_;
    pickedUp = false;
    direction = direction_;
    }

//Setters
void Passenger::addTurn(){
	turns++;
    }
void Passenger::loadPassenger(){
    if (pickedUp == false){
        pickedUp = true;
    }
}
//Getters
int Passenger::getTurns(){
    return turns;
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
bool Passenger::getPickedUp(){
    return pickedUp;
}
