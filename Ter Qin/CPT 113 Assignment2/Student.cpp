#include "Student.h"
#include<iomanip>

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
	cout << "Matric Num: " << matric << endl << endl;
	cout << "Total Units Taken: " << units << endl;

	//if (units < 15)
		//cout << "Minimum units should be 15 units!" << endl;
}

void Student::Grade()
{
	double point = 0.0;
	int unit = course.getTotalUnit();
	course.keyInGrade(point);
	cout << fixed << setprecision(2);
	cout << "Total CGPA: " << point / unit << endl;
	if ((point / unit) <= 2.00)
		cout << "Unfortunately,  you have failed this semester!" << endl;
	else
		cout << "Congratulations! Good luck in the next semester!" << endl;
}

void Student::setName(string n)
{
	name = n;
}

void Student::setMatric(int m)
{
	matric = m;
}

void Student::setStudentCourse(Course& c)
{
	int temp = 0;
	course.appendNode(c, temp);
}

bool Student::searchCourse(string code, int unit)
{
	Course temp;
	temp.setCourse(code, unit);
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

void Student::operator=(const Student& right)
{
	Student::reset();
	this->name = right.name;
	this->matric = right.matric;
	this->course.setSame(right.course);
}

void LinkList<Student>::displayListS()
{
	ListNode<Student>* nodeptr = head;
	while (nodeptr)
	{
		nodeptr->value.displayDetails();
		nodeptr = nodeptr->next;
	}
}
