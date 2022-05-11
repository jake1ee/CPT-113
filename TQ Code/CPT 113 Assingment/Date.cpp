#include "Date.h"
#include <iostream>
#include <string>

Date::Date()
{
	day=month=year=0;
}

Date::Date(int d, int m, int y) //alternate constructor
{
	this->day = d;
	this->month = m;
	this->year = y;	
	checkValidity();
}

void Date::setDate(int d, int m, int y) //set values of dates
{
	this->day = d;
	this->month = m;
	this->year = y;	
}

void Date::printDate() //to print date out in dd/mm/yyyy format
{
	cout << day << "/" << month << "/" << year << "/" << endl;	
}

void Date::checkValidity()
{
	if (day>28)
	{
		month += day % 28;
		day /= 28;
	}
}
