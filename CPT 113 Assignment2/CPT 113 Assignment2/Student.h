#ifndef STUDENT_H
#define STUDENT_H
#include "LinkList.h"
#include<string>

using namespace std;

class Student
{
private:
	string name;
	int matric;
	struct Course
	{
		string CourseCode;
		int CourseUnit;
	};
	LinkList<Course> course;

public:
	Student();
	~Student();
};

Student::Student()
{
}

Student::~Student()
{
}

#endif // !STUDENT_H
