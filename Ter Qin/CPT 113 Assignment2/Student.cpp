#include "Student.h"
#include<iomanip>

Student::Student()		//constructor
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

void Student::displayDetails()	//display student information
{
	cout << "---------------------------------------------------------------" << endl;
	cout << "Name: " << name << endl;
	cout << "Matric Num: " << matric << endl << endl;
	cout << "--------------------------Course Taken-------------------------- " << endl;
	course.displayListC();
}

void Student::displayUnits()	//display student's total unit
{
	int units = course.getTotalUnit();
	cout << "Name: " << name << endl;
	cout << "Matric Num: " << matric << endl << endl;
	cout << "--------------------------Course Taken-------------------------- " << endl;
	course.displayListC();
	cout << "Total Units Taken: " << units << endl;
}

void Student::Grade()			//display student's CGPA
{
	double point = 0.0;
	int unit = course.getTotalUnit();
	course.keyInGrade(point);
	cout << fixed << setprecision(2);
	cout << "Total units: " << unit << endl;
	cout << "Total GP: " << point << endl;
	cout << "Total CGPA: " << point / unit << endl;
	if ((point / unit) <= 2.00)
		cout << "Unfortunately,  you have failed this semester!" << endl;
	else
		cout << "Congratulations, you have passed this semester! Keep it up in the next semester!" << endl;
}

void Student::setName(string n)		//set name
{
	name = n;
}

void Student::setMatric(int m)		//set matric number
{
	matric = m;
}

void Student::setStudentCourse(Course& c)	//set student course
{
	int temp = 0;
	course.appendNode(c, temp);
}

bool Student::searchCourse(string code, int unit)	//search student course
{
	Course temp;
	temp.setCourse(code, unit);
	if (course.searchNode(temp))
	{
		return true;
	}
	return false;

}

int Student::getMatric()		//get matric number
{
	return matric;
}
string Student::getName()		//get name
{
	return name;
}

bool Student::operator==(const Student& right)
{
	if (this->matric == right.matric)
		return true;
	else
		return false;
}

void Student::operator=(const Student& right)
{
	Student::reset();
	this->name = right.name;
	this->matric = right.matric;
	this->course.setSame(right.course);
}
