
#pragma once
class Simulation {
private:
    int clock;
    int arrival_time;
    int waiting_time; //max_processing_time in simulator
    int my_random;
    double Frequency;
    std::list<int> simPassengers;
   
public:
    Simulation();
    int elevatorFloor;
    int MaxTurn;
    int waitTime;
    int get_arrival_time (){ return arrival_time;}
    int get_waiting_time (){ return waiting_time;}
   
    void Simulation :: Simulation (int elevatorFloor, int MaxTurns, double Frequency );
    bool Simulation :: genuser ();
  
  
}
