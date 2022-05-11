#ifndef DATE_H
#define DATE_H
#include<string>

using namespace std;

class Date
{
protected:
	int day;
	int month;
	int year;
	void checkValidity();
public:
	Date();
	~Date();

};
#endif // !DATE_H
