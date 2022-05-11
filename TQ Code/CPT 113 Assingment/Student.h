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
	long int IC;

	
public:
	Student();
	~Student();
};
#endif // !STUDENT_H
