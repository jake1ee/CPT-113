#ifndef STUDENT_H
#define STUDENT_H

#include "LinkList.h"
#include<string>


class Student
{
private:
	string name;
	int matric;
	LinkList<Course> course;

public:
	Student();
	void displayDetails();
	void setName(string);
	void setMatric(int);
	void setCourse(string, string);
	int getMatric();
	string getName();
};

#endif // !STUDENT_H
