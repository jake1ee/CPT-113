#include "Student.h"
#include <iostream>
#include <string>

using namespace std;

Student::Student()
{
	gender=0;
	name=email=phone="";
	matricNum=0;
	IC="";
}

Student::Student(char gender, string name, string email, string phone, int matNum, string ic)
{
	this->gender = gender;
	this->name = name;
	this->email = email;
	this->phone = phone;
	this->matricNum = matNum;
	this->IC = ic;
}

void Student::setStudent(char gender, string name, string email, string phone, int matNum, string ic)
{
	this->gender = gender;
	this->name = name;
	this->email = email;
	this->phone = phone;
	this->matricNum = matNum;
	this->IC = ic;
}

bool Student::operator==(string& IC)
{
	if (this->IC != IC)
	{
		return false;
	}
	return true;
}

Student::~Student()
{
	gender=0;
	name=email=phone="";
	matricNum=0;
	IC="";
}
