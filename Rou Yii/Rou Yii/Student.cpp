#include "Student.h"

Student::Student()
{
	name = "";
	matric = NULL;
}

void Student::displayDetails()
{
	cout << "Name: " << name << endl;
	cout << "Matric Num: " << matric << endl;
	course.DisplayStudentCourse();
}

void Student::setName(string n)
{
	name = n;
}

void Student::setMatric(int m)
{
	matric = m;
}

int Student::getMatric()
{
	return matric;
}
string Student::getName()
{
	return name;
}
bool Student::operator==(const Student& right)
{
	if (this->name == right.name && this->matric == right.matric)
		return true;
	else
		return false;
}