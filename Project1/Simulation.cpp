#include "Simulator.h"
#include "ElevatorList.h"
#include <iostream>
Simulator :: Simulator(double thefrequency, int theprocessing_time, int &thetotal_floors)
	{
		frequency = thefrequency; processing_time = theprocessing_time; totalfloors = thetotal_floors;
	}
Simulator :: Simulator() 
	{ 
		frequency = .5; processing_time = 30; int totalfloors = 15;
	}
void Simulator::run_simulation()
	{
		for (clock = 0; clock < total_time_allowed(); clock++)
		{
			uplist.check_new_arrival(clock, show_all);

			downlist.check_new_arrival(clock, show_all);

			if (clock >= time_done) start_serve();

		}
	}
void Simulator::start_serve() 
	{
		if (!uplist.empty() || downlist.empty())
		{
			time_done = uplist.update(clock, show_all);
		}
		else if (!downlist.empty() || uplist.empty())
		{
			time_done = downlist.update(clock, show_all);
		}
		else if (show_all) {
			cout << "Time is " << clock << ": Server is idle\n";
		}
	}
void Simulator::show_stats(const User passenger, ElevatorLists up, ElevatorLists down)
	{
		cout << "\n The number of passengers served going up was "
			<< up.get_num_served() << endl;
		double average_waiting_time = double(up.get_total_wait())
			/ double(up.get_num_served());

		cout << " with an average waiting time of "
			<< average_waiting_time << endl;

		cout << "\n The number of passengers served going up was "
			<< down.get_num_served() << endl;
		double average_waiting_time = double(down.get_total_wait())
			/ double(down.get_num_served());

		cout << " with an average waiting time of "
			<< average_waiting_time << endl;

	}
float frequency_of_arrivals() {}
int max_processing_time() {}
int total_time_allowed() {}
bool show_all() {}
