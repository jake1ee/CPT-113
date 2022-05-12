//include header files
#include "Date.h"
#include "Operation.h"
#include "Stay.h"
#include "Student.h"

#include<iostream>
#include <string>
using namespace std;

void displayStart();

//main 
int main()
{
	int choice; //user's choice whether to choose 1/2/3
	displayStart();
	cin >> choice;
	while (choice!=3)
	{
		if (choice==1)
		{
			//register function
			displayStart();
			cin >> choice;
		}
		
		else if (choice==2)
		{
			//fee function
			displayStart();
			cin >> choice;
		}
		
		//if user enter any other number than 1-3 then will prompt error
		else if (choice >3 || choice <1) 
		{
			cout << "\nInvalid choice." << endl;
			displayStart();
			cin >> choice;
		}
	}
	
	return 0;
}

void displayStart() //display choices for users to choose.
{
	int choice; //user's choice whether to choose 1/2/3
	Operation operation;
	do
	{
	cout << "\nWelcome to Universiti Sains Malaysia." << endl;
	cout << "---------------------------------------" << endl;
	cout << "Options:" << endl;
	cout << "1. Registration for Desasiswa.\n"
		<< "2. Payment.\n"
		<< "3. Exit.\n" << endl;
	cout << "Choices:" ;
	cin >> choice;
	switch (choice)
	{
	case 1:
		operation.Registration();
	case 2:
		operation.CalculateFee();
	case 3:
		cout << "Exit Program Thankyou for using this program." << endl;
	default:
		cout << "Invalid Choice Please Enter Again\n" << endl;
		break;
	}
	} while (choice != 3);
}


