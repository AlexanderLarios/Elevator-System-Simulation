#include "elevator.h"
#include "Random.h"
struct User {
public:
      User(){};
      User(int defaultFloor, int finalFloor, int direction_);
      //~User();
      int TurnsSinceSpawn
      int defaultFloor; //should be type random instead of int
      int finalFloor;//should be type random instead of int
      Random my_random; //making those random should allow us to get rid of this line...
  
      int direction;
      bool pickedUp;
      
      static void set_waiting_time(int wt){ waiting_time = wt;}
      
};
