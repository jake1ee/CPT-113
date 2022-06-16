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
		CourseUnit = NULL;
		grade = "";
	}

	void displayCourse()	//to display course code and unit
	{
		cout << "Course Code: " << CourseCode << endl;
		cout << "Course Unit: " << CourseUnit << endl;
	}

	void setCourse(string code = "", int unit = 0)	//set course code and unit
	{
		CourseCode = code;
		CourseUnit = unit;
	}
	void setGrade(string g)							//set course grade
	{
		grade = g;
	}

	string getCode()								//get course code
	{
		return CourseCode;
	}

	int getUnit()									//get course unit
	{
		return CourseUnit;
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
	string CourseCode, grade;
	int CourseUnit;
};


#endif // !COURSE_H
