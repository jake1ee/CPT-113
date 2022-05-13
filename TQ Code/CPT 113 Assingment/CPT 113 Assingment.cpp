//include header files
#include "Date.h"
#include "Operation.h"
#include "Stay.h"
#include "Student.h"

#include<iostream>
#include <string>
using namespace std;

//function prototype
void displayStart(); 

//main 
int main()
{
	displayStart();
	return 0;
}

//This function display choices for users to choose.
void displayStart() 
{
	int choice; //user's choice whether to choose 1/2/3
	Operation operation;
	do
	{
	cout << "\nWelcome to Universiti Sains Malaysia." << endl;
	cout << "------------------------------------------------" << endl;
	cout << "Options:" << endl;
	cout << "1. Registration for Desasiswa.\n"
		<< "2. Payment.\n"
		<< "3. Exit Program.\n" << endl;
	cout << "Choices (1 / 2 / 3):" ;
	cin >> choice;
	switch (choice)
	{
	case 1:
		operation.Registration(); //calling registration function
		break;
	case 2:
		operation.CalculateFee(); //calling calculate fee function
		break;
	case 3:
		cout << "Exit Program -- Thankyou for using this program!" << endl;
		break;
	default:
		cout << "Invalid Choice -- Please Enter Again\n" << endl;
		break;
	}
	} while (choice != 3);
}


