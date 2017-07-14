#pragma once
class Passenger{
//Private members
private:
    int turns=0;
    int direction;
    int startFloor;
    int endFloor;
    bool pickedUp = false;
//Public Members
public:
    //constructor
    Passenger(int defaultFloor, int finalFloor, int direction_);
    void addTurn();
    void loadPassenger();
    //getter
    int getTurns();
    int getStartFloor();
    int getEndFloor();
    int getDirection();
    bool getPickedUp();
};

