 #include "Operation.h"
#include<iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// limitations: all students accessible to this program are from the same course
const double TUITION_FEE = 1130.00; // tuition fees
const double DAILY_RATE = 3.50; //daily rate for room

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

double Operation::CalculateFee() 
{
	int daysDorm = calcDays();
	double totalfee;
	totalfee = TUITION_FEE + (DAILY_RATE * daysDorm);
	
	return totalfee;	
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

int Operation::calcDays()
{
	string IC;
	int line=0;
	string line1 = " ";
	string name = " ";
	char gender = ' ';
	int matricNum;
	string icNum = " ";
	string email = " ";
	string phone = " ";
	string desa = " ";
	int day1;
	int month1;
	int year1;
	int day2;
	int month2;
	int year2;
	string d = " day ";
	string m = " month ";
	string y = " year ";
	int daysDorm; //days from check in->check out(today)
	Student student;
	Date date;
		
	cout << "Input Identification Number: ";
	cin >> IC;
	
	fstream datafile;
	readInputTxt(); //read DesaStay.txt file

	//if the file was successfully opened, continue.
	if (datafile)
	{
		//read an item from the file
		while(getline(datafile,line1))
		{
			datafile >> name >> gender >> matricNum >> icNum >>  email >> phone >>
			day1 >> month1 >> year1 >> desa;
			if (icNum == IC)
			{
				student.setStudent(gender, name, email, phone, matricNum, icNum);
				day2 = checkoutDate(d);
				month2 = checkoutDate(m);
				year2 = checkoutDate(y);
				date.setDate (day1, month1, year1, day2, month2, year2);
				daysDorm = date.getNumDays();
			} 
			else
			{
				cout << "You are not registered in any desasiswa." << endl;
				daysDorm = 0;
			}
		}
		
		//close the file
		datafile.close();
	}
	else
	{
		cout << "ERROR: cannot open the file." << endl;
	}
	
	return daysDorm;
}

//function to prompt user to input checkout day, month, year 
//used in calcDays function
int Operation::checkoutDate(string a)
{
	int date;
	cout << "Enter checkout" << a << ": ";
	cin >> date;
	
	return date; 
}
















