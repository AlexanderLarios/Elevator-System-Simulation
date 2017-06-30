//Main.cpp
//CS303 Project 1 
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	cout << "Welcome To Elevator System Management..." << endl;
	int choice; //choice from menu
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
		}
		else if (choice == 2)
		{
			// Call sim function with predetermined peramter set 2
			cout << "Elevator Simulation 2" << endl;
		}
		else if (choice == 3)
		{
			// Ask user about peramter choices then call sim with user defined peramters
			cout << "Elevator Simulation 3" << endl;
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
