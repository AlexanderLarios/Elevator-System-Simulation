#pragma once
#include <list>	
#include <iterator>
#include "Random.h"
#include "Simulator.h"
using namespace std;

struct User
{
	int defaultfloor;
	int finalfloor;
	int starttime;

};
class ElevatorLists
{
public:
	//constructor
	ElevatorLists(int dfloor, int ffloor, int clock);

	//adds people to their respected lists while reading out info
	void check_new_arrival(int clock, bool show_all);

	//
	int getDeaultFloor();

	//
	int getCurrentFloor();

	//
	int getDirection();

	//
	int get_num_served();

	//
	int get_total_wait();
private:
	list <User> uplist;
	list <User> downlist;
	int total_wait;
	int number_served;
	int my_random;
};
