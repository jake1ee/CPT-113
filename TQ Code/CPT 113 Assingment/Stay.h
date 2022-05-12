#ifndef STAY_H
#define STAY_H
#include<string>
#include<iostream>
#include "Date.h"

using namespace std;
class Student;

class Stay
{
private:
	Student *student[20];
	string txtFiles;
protected:
	string Desa;
public:
	Stay()
	{
		cout << "Stay constructor call";
		txtFiles = "DesaStay.txt";
	}
	void readInputTxt();
	void writeTxt(char&, string&, string&, string&, string&, int&, int&, int&, int&);

	~Stay()
	{
		Desa=txtFiles=
	}


};
#endif // !STAY_H
