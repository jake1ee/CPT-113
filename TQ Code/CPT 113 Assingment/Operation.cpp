 #include "Operation.h"
#include<iostream>
#include<iomanip>
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

void Operation::CalculateFee() 
{
	int daysDorm = calcDays();
	double totalfee;
	totalfee = TUITION_FEE + (DAILY_RATE * daysDorm);
	
	system("cls");

	displayData(student);
	cout << "Num Day Stay: " << daysDorm << " Days" << endl;
	cout << fixed << setprecision(2) << endl;
	cout << "Fee: RM" << totalfee << endl;
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

	do
	{
	cout << "Gender(M/F): ";
	cin >> gender;
	} while (gender != 'M' && gender != 'F');
	
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
	
	do
	{
	cout << "CheckIn Date: " << endl;
	checkDate(day, month, year);
	} while ((month < 0 || month>12) || day < 0);
	

	writeTxt(gender, name, email, phone, IC, matricNum, day, month, year);
}

int Operation::calcDays()
{
	char gender = ' ';
	bool regis = false;

	string IC;
	string skip = " ";
	string name = " ";
	string icNum = " ";
	string email = " ";
	string phone = " ";
	string desa = " ";

	int matricNum;

	int day1;
	int month1;
	int year1;

	int day2;
	int month2;
	int year2;


	int daysDorm = 0; //days from check in->check out(today)
		
	cout << "Input Identification Number: ";
	cin >> IC;
	
	fstream dataFile;
	dataFile.open("DesaStay2.txt", ios::in); //read DesaStay.txt file

	//if the file was successfully opened, continue.
	if (dataFile)
	{
		//read an item from the file
		while(!dataFile.eof())
		{
			getline(dataFile, name, '\t');
			dataFile.get(gender);
			getline(dataFile, skip, '\t');
			dataFile >> matricNum;
			getline(dataFile, skip, '\t');
			getline(dataFile, icNum, '\t');
			getline(dataFile, email, '\t');
			getline(dataFile, phone, '\t');
			dataFile >> day1;
			getline(dataFile, skip, '/');
			dataFile >> month1;
			getline(dataFile, skip, '/');
			dataFile >> year1;
			getline(dataFile, skip, '\t');
			getline(dataFile, desa);

			student.setStudent(gender, name, email, phone, matricNum, icNum);
			if (student == IC)
			{
				cout << "Check Out Date: " << endl;
				checkDate(day2, month2, year2);
				date.setDate (day1, month1, year1, day2, month2, year2);
				daysDorm = date.getNumDays();
				regis = true;
				break;
			} 
		}				
		if (!regis)
			cout << "You are not registered in any desasiswa." << endl;
		
		//close the file
		dataFile.close();
	}
	else
	{
		cout << "ERROR: cannot open the file." << endl;
	}
	return daysDorm;
}


//function to prompt user to input checkout day, month, year 
//used in calcDays function
void Operation::checkDate(int& day, int& month, int& year)
{
	cout << "Year: ";
	cin >> year;
	cout << "Month: ";
	cin >> month;
	cout << "Day: ";
	cin >> day;
}
