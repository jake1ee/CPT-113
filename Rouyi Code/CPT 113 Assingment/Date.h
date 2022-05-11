#ifndef DATE_H
#define DATE_H
#include<string>

using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;
	void checkValidity();
public:
	Date();
	~Date();
	string  getDate();
};
#endif // !DATE_H
