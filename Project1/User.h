#pragma once
class User{
private:
    int waitingTime;
    int direction;
    int startFloor;
    int endFloor;
    bool pickedUp;
    
public:
    
    User(int defaultFloor, int finalFloor, int direction_);
    void setWT(int wt);
    int getWT();
    int getStartFloor();
    int getEndFloor();
    int getDirection();
    

};

