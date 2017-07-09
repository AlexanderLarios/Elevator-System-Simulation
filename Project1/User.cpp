#include "User.h"

User :: User(int direction_, int defaultFloor, int finalFloor){
    startFloor = defaultFloor;
    endFloor = finalFloor;
    pickedUp = false;
    if(defaultFloor < finalFloor){
    direction = 1 ;
    }
    else 
        direction = -1;
    
}
