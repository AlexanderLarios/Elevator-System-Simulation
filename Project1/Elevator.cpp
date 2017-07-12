#include "ElevatorList.h"
#include "Random.h"
using namespace std;

ElevatorLists::ElevatorLists(int dfloor, int ffloor, int clock)
{
	User next_passenger; 
	next_passenger.defaultfloor = dfloor;
	next_passenger.finalfloor = ffloor;
	next_passenger.starttime = clock;
}
User :: User(int arrive_time)
void check_new_arrival(int clock, bool show_all)
{
	while (clock > 0)
	{
		if (my_random.next_double() < frequency)
		{
			while (int a = my_random.next_int())
			{
				if (a > 0 && a < totalfloors)
				{
					defaultfloor = a;
				}
				if (int B = my_random.next_int() > 0 && B < totalfloors)
				{
					finalfloor = a;
					break;
				}
			}
		}
	}
	if (a > B) { direction = -1; downlist.push(User(clock)); }
	if (a < B) { direction = 1;	uplist.push(User(clock));	}
	if (a == B) { direction = 0; dropoff(); }
	if (show_all && direction == 1)
	{
		cout << "Time is " << clock << ": " << uplist << " arrival, new list size is " << uplist.size() << endl;
	}
	if (show_all && direction == -1)
	{
		cout << "Time is " << clock << ": " << downlist << " arrival, new list size is " << downlist.size() << endl;
	}
}

int ElevatorList::update(int clock, bool show_all)
{	if(User.direction == 1)
	{
		User next_passenger = uplist.front();
		uplist.pop();

	}

	if (User.direction == -1)
	{
		User next_passenger = downlist.front();
		downlist.pop();
	}

	int time_stamp = next_passenger.get_arrival_time();
	int wait = clock - time_stamp;
	total_wait += wait;
	number_served++;

	if (show_all && User.direction == 1)
	{
		cout << "Time is " << clock << ": " << uplist << " arrival, new list size is " << uplist.size() << endl;
	}

	if (show_all && User.direction == -1)
	{
		cout << "Time is " << clock << ": " << downlist << " arrival, new list size is " << downlist.size() << endl;
	}

	return (clock + next_passenger.get_processing_time());

}


