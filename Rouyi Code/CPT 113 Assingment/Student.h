#ifndef STUDENT_H
#define STUDENT_H
#include<string>

using namespace std;

class Student
{
	private:
		char gender;
		string name;
		string email;
		string phone;
		int matricNum;
		string course;
		
	public:
		Student();
		~Student();
		Student(char, string, string, string, int, long int);
		
};
#endif // !STUDENT_H
