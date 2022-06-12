#include "Student.h"

Student::Student()
{
	name = "";
	matric = NULL;
}

void Student::reset()
{
	name = "";
	matric = NULL;
	course.~LinkList();
	

}

void Student::displayDetails()
{
	cout << "Name: " << name << endl;
	cout << "Matric Num: " << matric << endl;
	cout << "Course Taken: " << endl << endl;
	course.displayListC();
}

void Student::displayUnits()
{
	int units = course.getTotalUnit();
	cout << "Name: " << name << endl;
	cout << "Matric Num: " << matric << endl;
	cout << "Total Units Taken: " << units << endl;
	
}

void Student::setName(string n)
{
	name = n;
}

void Student::setMatric(int m)
{
	matric = m;
}

void Student::setStudentCourse(Course c)
{
	int temp = 0;
	course.appendNode(c,temp);
}

bool Student::searchCourse(string code, string unit)
{
	Course temp;
	temp.setCourse(code,unit);
	if (course.searchNode(temp))
	{
		return true;
	}
	return false;

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