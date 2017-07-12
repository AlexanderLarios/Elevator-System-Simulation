#pragma once
class Passenger{
//Private members
private:
    int waitingTime;
    int direction;
    int startFloor;
    int endFloor;
    bool pickedUp;
//Public Members
public:
    //constructor
    Passenger(int defaultFloor, int finalFloor, int direction_);
    //setter
    void setWT(int wt);
    //getter
    int getWT();
    int getStartFloor();
    int getEndFloor();
    int getDirection();
};

