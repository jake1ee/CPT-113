#ifndef DATE_H
#define DATE_H
#include<string>

using namespace std;

const int monthDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

struct DateFormat{
		int d, m, y;
	};
	
class Date
{
protected:
	DateFormat CheckIn; //check in date
	DateFormat CheckOut; //check out date
	int NumDays;
	void checkValidity();
public:
	Date();
	Date(int, int, int, int, int, int);
	void setDate(int, int, int, int, int, int);
	int getNumDays();
	void getDifference(DateFormat CheckIn, DateFormat CheckOut);
};
#endif // !DATE_H
