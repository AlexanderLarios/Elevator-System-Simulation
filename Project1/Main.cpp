//Main.cpp
//CS303 Project 1 
#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <iterator>
#include "Elevator.h"
using namespace std;

//interface functions

//function to call elevator
// we may need a wrapper for distribution logic for multiple elevator systems.
/*
void callElevator(int floor,bool direction)
{
	if (floor == 0) 
	{
		//LogicElevator.called(floor,true);
	}
	else if(floor == levels)
	{
		//LogicElevator.called(floor,false);
	}

	else 
	{
		//LogicElevator.called(floor,direction);
	}
}
//function for elevator commands from inner pannel
void floorSelection(int floor) {

}
*/
//Global variables
//Main loop
int main()
{
	cout << "Welcome To Elevator System Management..." << endl;
	int choice; //choice from menu
	int levels;//Floors in building
	int numElevators; // Number elevators
	do // Main do while loop until exit is choosen
	{
		//Displaying Options for the menu
		
		cout << "Main Menu" << endl;
		cout << "1) Run Elevator Simulation 1 " << endl;
		cout << "2) Run Elevator Simulation 2 " << endl;
		cout << "3) Run Custom Elevator Simulation" << endl;
		cout << "4) Exit Program " << endl;

		//Ask user to make choice
		cout << "Please select an option : ";
		cin >> choice;  

		if (choice == 1)
		{
			//Call sim function with predetermined perameter set 1
			cout << "Elevator Simulation 1" << endl;
			levels = 10;
			numElevators = 1;
		}
		else if (choice == 2)
		{
			// Call sim function with predetermined perameter set 2
			cout << "Elevator Simulation 2" << endl;
			levels = 10;
			numElevators = 2;
		}
		else if (choice == 3)
		{
			// Ask user about perameter choices then call sim with user defined perameters
			cout << "Elevator Simulation 3" << endl;
			string strInput = "";
			

			while (true)
			{
				cout << "Please enter number of floors that elevator(s) will service:" << endl;
				getline(cin, strInput);

				// This code converts from string to number safely.
				stringstream myStream(strInput);
				if ((myStream >> levels))
					break;
				cout << "Invalid input, please try again" << endl;
			}
			strInput = "";
			while (true)
			{
				cout << "Please enter number of elevators in service:" << endl;
				getline(cin, strInput);

				// This code converts from string to number safely.
				stringstream myStream(strInput);
				if ((myStream >> numElevators))
					break;
				cout << "Invalid input, please try again" << endl;
			}

		}
		else if (choice == 4) //Quit
		{
			cout << "Closing Elevator System Management..." << endl;
		}
		else //bad input
		{
			//Displaying error message
			cout << "Invalid Input" << endl;
		}
	} while (choice != 4);  //base case of do-while loop

	return 0;
}
