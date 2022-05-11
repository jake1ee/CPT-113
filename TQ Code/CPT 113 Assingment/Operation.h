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
	Operation();
	~Operation();

private:
	Student student;
	Date date;

};

#endif // !OPERATION_H
