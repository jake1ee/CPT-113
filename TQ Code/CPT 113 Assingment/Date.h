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
	DateFormat dt1; //check in date
	DateFormat dt2; //check out date
	int NumDays = getDifference(dt1, dt2);
	
	void checkValidity();
public:
	Date();
	~Date();
	Date(int, int, int, int, int, int);
	void setDate(int, int, int, int, int, int);
	int getNumDays();
	int countLeapYears(DateFormat d);
	int getDifference(DateFormat dt1, DateFormat dt2);
};
#endif // !DATE_H
