#include "Stay.h"
#include<iostream>
#include<fstream>

using namespace std;


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
		cout << "Data has been written to the file" << endl;
	}
	else
	{
		
		cout << "Error Opening Files" << endl;
		exit(EXIT_FAILURE);
	}
	dataFile.close();
}

