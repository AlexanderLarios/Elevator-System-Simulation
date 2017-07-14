//Main.cpp
//CS303 Project 1 
#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <iterator>
#include "Elevator.h"
#include "Simulation.h"
#include "Passenger.h"
using namespace std;

//interface functions
//Global variables
//Main loop
int main(){
	
	cout << "Welcome To Elevator System Management..." << endl;
	int choice; //choice from menu
	int levels;//Floors in building
	int maxTurns;
	int spawnRate;
	do // Main do while loop until exit is choosen
	{
		//Displaying Options for the menu
		
		cout << "Main Menu" << endl;
		cout << "1) Run Elevator Simulation" << endl;
		cout << "2) Exit Program " << endl;

		//Ask user to make choice
		cout << "Please select an option : ";
		cin >> choice;  

		if (choice == 1)
		{
			//Call sim function with predetermined perameter set 1
			cout << "Elevator Simulation 1" << endl;
			levels = 10;
			spawnRate = 50;
			maxTurns = 30;
			Simulation Sim = Simulation(levels, maxTurns, spawnRate);
			Sim.simulate();
            }
		else if (choice == 2) //Quit
		{
			cout << "Closing Elevator System Management..." << endl;
		}
		else //bad input
		{
			//Displaying error message
			cout << "Invalid Input" << endl;
		}
	} while (choice != 2);  //base case of do-while loop

	return 0;
}
