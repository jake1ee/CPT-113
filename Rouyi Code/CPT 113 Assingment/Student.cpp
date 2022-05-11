#include "Student.h"
#include <string>
#include <iostream>
using namespace std;

Student::Student()
{
	gender='';
	name=email=phone="";
	matricNum=0;
	IC=0;
}

Student::Student(char gender, string name, string email, string phone, int matNum, long int ic)
{
	this->gender = gender;
	this->name = name;
	this->email = email;
	this->phone = phone;
	this->matricNum = matNum;
	this->IC = ic;
}

