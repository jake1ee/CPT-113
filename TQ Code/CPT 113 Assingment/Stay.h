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
	Student* student;
protected:
	string Desa;
public:
	void writeTxt(char&, string&, string&, string&, string&, int&, int&, int&, int&);


};
#endif // !STAY_H