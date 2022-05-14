#ifndef OPERATION_H
#define OPERATION_H
#include "Student.h"
#include "Stay.h"

using namespace std;

class Operation:public Stay //inheritance from class stay
{
public:
	void Registration(); 
	void CalculateFee();
	void checkDate(int&, int&, int&);
	int calcDays();
	void InputMenu();
	int DesaMenu();

private:
	Student student[2]; //composition class student
	Date date; //composition class date
	bool regis = false;
};

#endif // !OPERATION_H
