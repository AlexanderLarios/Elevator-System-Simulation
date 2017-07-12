//lots similar here I wouldnt accept my changes HAHAHAH!
#pragma once
#include "ElevatorList.h"
#include <cstdlib>
class Simulator {
public:
	/*Set: frequency_of_arrivals, total_time, show_all*/
	Simulator(double .5, int 30, int &0);
	Simulator();
	void run_simulation();
	void start_serve();
	void show_stats(const User passenger, ElevatorLists up, ElevatorLists down);
	double frequency_of_arrivals();
	int max_processing_time();
	int total_time_allowed();
	bool show_all();
private:
	double frequency;
	int processing_time;
	int totalfloors;
	int clock;
	int time_done;
};
