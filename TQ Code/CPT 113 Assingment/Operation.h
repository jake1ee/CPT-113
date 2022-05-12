#ifndef OPERATION_H
#define OPERATION_H
#include "Student.h"
#include "Stay.h"

using namespace std;

class Operation:public Stay
{
public:
	void Registration();
	void CalculateFee();
	void checkDate(int&, int&, int&);
	int calcDays();
	void InputMenu();
	int DesaMenu();

private:
	Student student;
	Date date;

};

#endif // !OPERATION_H
