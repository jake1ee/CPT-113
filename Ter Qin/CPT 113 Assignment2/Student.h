#ifndef STUDENT_H
#define STUDENT_H

#include "LinkList.h"
#include<string>

class Student
{
private:
	string name;
	int matric;
	LinkList course;

public:
	Student();
	void displayDetails();
	void setName(string);
	void setMatric(int);
	int getMatric();
	string getName();
	bool operator==(const Student&);
};

#endif // !STUDENT_H
