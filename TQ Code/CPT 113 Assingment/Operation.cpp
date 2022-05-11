#include "Operation.h"
#include<iostream>

using namespace std;

void Operation::Registration()
{
	int desa = DesaMenu();

	switch (desa)
	{
	case 1:
		Desa = "Restu";
		InputMenu();
		break;
	case 2:
		Desa = "Tekun";
		InputMenu();
		break;
	case 3:
		Desa = "Aman Damai";
		InputMenu();
		break;
	default:
		cout << "Invalid Desa Number" << endl;
		break;
	}
}
void Operation::CalculateFee() 
{

}
int Operation::DesaMenu()
{
	int choices;

	do
	{
	cout << "Please Select Desasiswa to Register:" << endl;
	cout << "1. Restu\n2. Tekun\n3. Aman Damai\n" << endl;
	cin >> choices;
	if (choices > 3 || choices < 1)
	{
		cout << "Invalid Output Please Enter Again." << endl;
	}
	} while (choices>3||choices<1);

	return choices;
	
}

void Operation::InputMenu()
{
	char gender;
	string name;
	string email;
	string phone;
	string IC;
	int matricNum;

	int day;
	int month;
	int year;

	cout << "Please Enter Your Personal Information:" << endl;
	cin.get();
	cout << "Name: ";
	getline(cin, name);
	cout << "Gender(M/F): ";
	cin >> gender;
	cin.get();
	cout << "Email: ";
	getline(cin, email);
	cout << "Phone Number: ";
	getline(cin, phone);
	cout << "Matric Number(Exp:159389): ";
	cin >> matricNum;
	cin.get();
	cout << "IC Number: ";
	getline(cin, IC);

	cout << "CheckIn Date: " << endl;
	cout << "Year: ";
	cin >> year;
	cout << "Month: ";
	cin >> month;
	cout << "Day: ";
	cin >> day;

	writeTxt(gender, name, email, phone, IC, matricNum, day, month, year);
}