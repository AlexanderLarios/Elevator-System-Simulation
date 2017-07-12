#pragma once
class Passenger{
//Private members
private:
    int turns;
    int direction;
    int startFloor;
    int endFloor;
    bool pickedUp;
//Public Members
public:
    //constructor
    Passenger(int defaultFloor, int finalFloor, int direction_);
    void addTurn();
    //getter
    int getTurns();
    int getStartFloor();
    int getEndFloor();
    int getDirection();
};

