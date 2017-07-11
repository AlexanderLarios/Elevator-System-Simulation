#pragma once
class User{
public:
    
    User();
    User(int defaultFloor, int finalFloor, int direction_);
    bool pickedUp;
    void setWT(int wt);
    
private:
    int waitingTime;
    int defaultFloor;
    int finalFloor;
    int direction;
    int startFloor;
    int endFloor;
};

