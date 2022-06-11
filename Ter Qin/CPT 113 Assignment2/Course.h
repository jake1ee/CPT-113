#ifndef COURSE_H
#define COURSE_H

#include <string>
#include<iostream>

using namespace std;

class Course
{
public:
	Course()
	{
		CourseCode = "";
		CourseUnit = "";
		grade = NULL;
	}

	void displayCourse()
	{
		cout << "Course Code: " << CourseCode << endl;
		cout << "Course Unit: " << CourseUnit << endl;
	}

	void setCourse(string code, string unit)
	{
		CourseCode = code;
		CourseUnit = unit;
	}
	void setGrade(int g)
	{
		grade = g;
	}

	string getCode()
	{
		return CourseCode;
	}

	string getUnit()
	{
		return CourseUnit;
	}

	double getGrade()
	{
		return grade;
	}

	bool operator ==(const Course& right)
	{
		if (this->CourseCode == right.CourseCode && this->CourseUnit == right.CourseUnit)
			return true;
		else
			return false;
	}

	void operator =(const Course& right)
	{
		this->CourseCode = right.CourseCode;
		this->CourseUnit = right.CourseUnit;
		this->grade = right.grade;
	}

private:
	string CourseCode,CourseUnit;
	double grade;

};
#endif // !COURSE_H
