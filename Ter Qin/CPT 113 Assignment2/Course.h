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
		gp = 0.0;
	}

	void displayCourse()
	{
		cout << "Course Code: " << CourseCode << endl;
		cout << "Course Unit: " << CourseUnit << endl;
	}

	void setCourse(string code = "", int unit = 0)
	{
		CourseCode = code;
		CourseUnit = unit;
	}
	void setGrade(string g)
	{
		grade = g;
		GradePoint();
	}

	string getCode()
	{
		return CourseCode;
	}

	int getUnit()
	{
		return CourseUnit;
	}

	void GradePoint()
	{
		if (grade == "A")
			gp = 4.00;
		else if (grade == "A-")
			gp = 3.67;
		else if (grade == "B+")
			gp = 3.33;
		else if (grade == "B")
			gp = 3.00;
		else if (grade == "B-")
			gp = 2.67;
		else if (grade == "C+")
			gp = 2.33;
		else if (grade == "C")
			gp = 2.00;
		else if (grade == "C-")
			gp = 1.67;
		else if (grade == "D+")
			gp = 1.33;
		else if (grade == "D")
			gp = 1.00;
		else if (grade == "D-")
			gp = 0.67;
		else
			gp = 0.00;
	}

	double getGradePoint()
	{
		return gp;
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
	double gp;

};


#endif // !COURSE_H
