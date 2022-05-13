#ifndef STUDENT_H
#define STUDENT_H
#include<string>
#include"Stay.h"


using namespace std;

class Student
{
private:
	char gender;
	string name;
	string email;
	string phone;
	int matricNum;
	string IC;

public:
	Student(); //constructor
	~Student(); //destructor
	Student(char, string, string, string, int, string); //alternate constructor
	void setStudent(char, string, string, string, int, string);
	friend void Stay::displayData(const Student); //friend
	bool operator==(string&); //operator overloading
};
#endif // !STUDENT_H
