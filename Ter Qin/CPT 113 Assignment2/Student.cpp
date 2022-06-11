#include "Student.h"
#include <fstream>

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
void Student::setCourse(string code, string unit)
{
	Course *temp = new Course;
	temp->setCourse(code, unit);
	course.appendNode(*temp);
	cout << 1;
}
int Student::getMatric()
{
	return matric;
}
string Student::getName()
{
	return name;
}

void LinkList<Student>::DisplayStudent()
{	
	ListNode<Student>* nodeptr = head;
	while (nodeptr != nullptr)
	{
		
		nodeptr->value.displayDetails();
		nodeptr = nodeptr->next;
	}
}