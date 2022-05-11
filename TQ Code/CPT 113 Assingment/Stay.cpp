#include "Stay.h"
#include<iostream>
#include<fstream>

using namespace std;

void Stay::readInputTxt()
{
	fstream dataFile;
	dataFile.open(txtFiles, ios::in);

}

void Stay::writeTxt(char &gender, string &name, string &email, string &phone, string &IC, int &matricNum, int &day, int &month, int &year)
{
	fstream dataFile;
	fstream ty;
	dataFile.open("C:\\Users\\A C E R\\Desktop\\CPT-113\\CPT 113 Assingment\\DesaStay.txt", ios::app | ios::out);

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
		cout << "Data has been write to the file" << endl;
	}
	else
	{
		
		cout << "Error Opening Files" << endl;
		exit(EXIT_FAILURE);
	}
	dataFile.close();
}

