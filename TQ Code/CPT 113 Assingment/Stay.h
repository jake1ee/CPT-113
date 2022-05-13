#ifndef STAY_H
#define STAY_H
#include<string>
#include<iostream>
#include "Date.h"

using namespace std;
class Student;

class Stay
{
protected:
	string Desa;
public:
	Stay() { Desa = ""; } //constructor
	~Stay() { Desa = ""; } //destructor
	void writeTxt(char&, string&, string&, string&, string&, int&, int&, int&, int&);
	void displayData(const Student);
};
#endif // !STAY_H
