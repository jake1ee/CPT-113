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
	void reset();
	void displayDetails();
	void setName(string);
	void setMatric(int);
	void setStudentCourse(Course);
	bool searchCourse(string, string);
	int getMatric();
	string getName();
	bool operator==(const Student&);
};

#endif // !STUDENT_H
