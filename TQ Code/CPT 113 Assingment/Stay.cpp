#include "Stay.h"
#include "Student.h"
#include<iostream>
#include<fstream>

using namespace std;

//This function is to write student info into txt file
void Stay::writeTxt(char &gender, string &name, string &email, string &phone, string &IC, int &matricNum, int &day, int &month, int &year)
{
	fstream dataFile;
	fstream ty;
	dataFile.open("DesaStay2.txt", ios::app | ios::out);

	if (dataFile.is_open())
	{	dataFile << endl;
		dataFile << name << "\t";
		dataFile << gender << "\t";
		dataFile << matricNum << "\t";
		dataFile << IC << "\t";
		dataFile << email << "\t";
		dataFile << phone << "\t";
		dataFile << day << "/" << month << "/" << year << "\t";
		dataFile << Desa;
		system("cls");
		cout << "Registered Successfully!" << endl;
	}
	else
	{
		
		cout << "Error Opening Files" << endl;
		exit(EXIT_FAILURE);
	}
	dataFile.close();
}

//This function is to print info for students that are staying in desa
void Stay::displayData(const Student info)
{
	cout << "------------------------------------------------" << endl;
	cout << "Personal Information: " << endl;
	cout << "Name: \t\t" << info.name << endl;
	cout << "Gender: \t" << info.gender << endl;
	cout << "Matric Num: \t" << info.matricNum << endl;
	cout << "IC: \t\t" << info.IC << endl;
	cout << "Email: \t\t" << info.email << endl;
	cout << "Phone: \t\t" << info.phone << endl;
	cout << "------------------------------------------------" << endl;
}
