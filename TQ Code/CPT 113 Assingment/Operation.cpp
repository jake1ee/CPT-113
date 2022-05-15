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

//This function is to prompt user to choose desasiswa
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

//This function is to calculates fees for student
void Operation::CalculateFee() 
{
	int daysDorm = calcDays();
	double totalfee;
	totalfee = TUITION_FEE + (DAILY_RATE * daysDorm);
	
	//system("cls");
	displayData(student[0]);
	if (regis)
	{
		date.displayDate();
		cout << "FEE INFORMATION:" << endl;
		cout << "------------------------------------------------" << endl;
		cout << "Days in dorm\t\t: " << daysDorm << " Days" << endl;
	}
	cout << fixed << setprecision(2);
	cout << "Dorm Daily Rate\t\t: RM" << DAILY_RATE << endl;
	cout << "Tuition Fee\t\t: RM" << TUITION_FEE << endl << endl;
	cout << "Total Fee\t\t: RM" << totalfee << endl;
}

//This function is to display desa choices and prompt user input
int Operation::DesaMenu()
{
	int choices;

	do
	{
	cout << "------------------------------------------------" << endl;
	cout << "\nPlease Select Desasiswa to Register:" << endl;
	cout << "1. Restu\n2. Tekun\n3. Aman Damai\n" << endl;
	cout << "Choices: ( 1 / 2 / 3 ): ";
	cin >> choices;
	if (choices > 3 || choices < 1)
	{
		cout << "Invalid Output -- Please Enter Again." << endl;
	}
	} while (choices>3||choices<1);

	return choices;
	
}

//This function is to prompt user to input personal details
void Operation::InputMenu()
{
	char gender;
	char skip;
	string name;
	string email;
	string phone;
	string IC;
	int matricNum;

	int day;
	int month;
	int year;
	
	cout << "------------------------------------------------" << endl;
	cout << "Please Enter Your Personal Information:" << endl;
	cin.get();
	cout << "Name: ";
	getline(cin, name);

	do
	{
	cout << "Gender ( M / F ): ";
	cin >> gender;
	} while (gender != 'M' && gender != 'F');
	cin.get();
	cout << "IC Number (Exp: 011231-02-5678): ";
	getline(cin, IC);
	if (checkIC(IC))
	{
		cout << "------------------------------------------------" << endl;
		cout << "Your Have Register In The Desasiswa" << endl;
	}
	else
	{
	cout << "Email (Exp: abcd123@gmail.com): ";
	getline(cin, email);
	cout << "Phone Number (Exp: 012-2347288): ";
	getline(cin, phone);
	cout << "Matric Number (Exp: 159389): ";
	cin >> matricNum;
	cin.get();

	do
	{
	cout << "\n------------------------------------------------" << endl;
	cout << "CheckIn Date: " << endl;
	checkDate(day, month, year);
	} while ((month < 0 || month>12) || day < 0);
	writeTxt(gender, name, email, phone, IC, matricNum, day, month, year);
	}
	
		cout << "Press Enter To Continue..." << endl;
		cin.get(skip);
	
	system("cls");
	
	
}

//This function is to calculate days stayed in dorm
int Operation::calcDays()
{
	char gender = ' ';

	string IC;
	string skip = " ";
	string name = " ";
	string icNum = " ";
	string email = " ";
	string phone = " ";
	string desa = " ";

	int matricNum;
	int MatricNum;
	int day1;
	int month1;
	int year1;

	int day2;
	int month2;
	int year2;


	int daysDorm = 0; //days from check in->check out(today)

	cout << "------------------------------------------------" << endl;
	cout<<"Enter Matric Num: ";
	cin >> MatricNum;
	cout << "Input Identification Number: ";
	cin >> IC;
	student[0].setStudent(' ', "", "", "", MatricNum, IC);
	
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

			student[1].setStudent(gender, name, email, phone, matricNum, icNum);
			if (student[0] == student[1]) //operator overloading
			{
				student[0] = student[1];
				cout << "------------------------------------------------" << endl;
				cout << "Check Out Date: " << endl;
				checkDate(day2, month2, year2);
				date.setDate (day1, month1, year1, day2, month2, year2);
				daysDorm = date.getNumDays();
				regis = true;
				break;
			} 
		}				
		if (!regis)
		{
			cout << "You are not registered in any desasiswa!" << endl;
			cout << "------------------------------------------------" << endl;
			cout << "Please Enter Your Personal Information:" << endl;
			cin.get();
			cout << "Name: ";
			getline(cin, name);

			do
			{
				cout << "Gender ( M / F ): ";
				cin >> gender;
			} while (gender != 'M' && gender != 'F');

			cin.get();
			cout << "Email (Exp: abcd123@gmail.com): ";
			getline(cin, email);
			cout << "Phone Number (Exp: 012-2347288): ";
			getline(cin, phone);

			student[0].setStudent(gender, name, email, phone, MatricNum, IC);
			
		}

		//close the file
		dataFile.close();
	}
	else
	{
		cout << "ERROR: cannot open the file." << endl;
	}
	return daysDorm;
}


//This function is to prompt user to input checkout day, month, year 
//used in calcDays function
void Operation::checkDate(int& day, int& month, int& year)
{
	do
	{
	cout << "\nYear: ";
	cin >> year;
	cout << "Month: ";
	cin >> month;
	cout << "Day: ";
	cin >> day;
	} while (month < 1 || month>12);
	
}

bool Operation::checkIC(const string& ic)
{
	string IC;
	string skip = " ";
	fstream dataFile;
	dataFile.open("DesaStay2.txt", ios::in);
	while (!dataFile.eof())
	{
		getline(dataFile, skip, '\t');
		getline(dataFile, skip, '\t');
		getline(dataFile, skip, '\t');
		getline(dataFile, IC, '\t');
		getline(dataFile, skip, '\t');
		getline(dataFile, skip, '\t');
		getline(dataFile, skip, '\t');
		getline(dataFile, skip, '\t');
		if (IC == ic)
		{
			return true;
		}
	}
	return false;
}
