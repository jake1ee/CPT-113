#include "Student.h"
#include <iostream>
#include <string>

using namespace std;

//constructor
Student::Student() 
{
	gender=0;
	name=email=phone="";
	matricNum=0;
	IC="";
}

//destructor
Student::~Student()
{
	gender = 0;
	name = email = phone = "";
	matricNum = 0;
	IC = "";
}

//alternate constructor
Student::Student(char gender, string name, string email, string phone, int matNum, string ic)
{
	this->gender = gender;
	this->name = name;
	this->email = email;
	this->phone = phone;
	this->matricNum = matNum;
	this->IC = ic;
}

//This function sets value for student's personal information
void Student::setStudent(char gender = ' ', string name = "", string email = "", string phone = "", int matNum = NULL, string ic = "")
{
	this->gender = gender;
	this->name = name;
	this->email = email;
	this->phone = phone;
	this->matricNum = matNum;
	this->IC = ic;
}

//operator overloading
bool Student::operator==(const Student& Right)
{
	if (this->matricNum !=Right.matricNum)
	{
		return false;
	}
	if (this->IC!=Right.IC)
	{
		return false;
	}
	return true;
}

void Student::operator=(const Student& Right)
{
	this->gender = Right.gender;
	this->name = Right.name;
	this->email = Right.email;
	this->phone = Right.phone;
	this->matricNum = Right.matricNum;
	this->IC = Right.IC;
}


