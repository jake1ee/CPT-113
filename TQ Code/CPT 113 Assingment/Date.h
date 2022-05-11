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
	Date(int, int, int);
	void setDate(int, int, int);
	void printDate();

};
#endif // !DATE_H
