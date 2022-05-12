#include "Date.h"
#include <iostream>
#include <string>

Date::Date()
{
	dt1=dt2={0,0,0};
}

Date::Date(int d1, int m1, int y1, int d2, int m2, int y2) //alternate constructor
{
	dt1.d = d1;
	dt1.m = m1;
	dt1.y = y1;
	dt2.d = d2;
	dt2.m = m2;
	dt2.y = y2;
//	checkValidity();
}

void Date::setDate(int d1, int m1, int y1, int d2, int m2, int y2) //set values of dates
{
	dt1.d = d1;
	dt1.m = m1;
	dt1.y = y1;
	dt2.d = d2;
	dt2.m = m2;
	dt2.y = y2;
}

//void Date::checkValidity()
//{
//	if (day>28)
//	{
//		month += day % 28;
//		day /= 28;
//	}
//}

int Date::getNumDays()
{
	return NumDays;
}

// This function counts number of
// leap years before the given date
int Date::countLeapYears(DateFormat d)
{
    int years = d.y;
 
    // Check if the current year needs to be
    //  considered for the count of leap years
    // or not
    if (d.m <= 2)
        years--;
 
    // An year is a leap year if it is a multiple of 4,
    // multiple of 400 and not a multiple of 100.
    return (years / 4) - (years / 100) + (years / 400);
}
 
// This function returns number of days between two given dates
int Date::getDifference(DateFormat dt1, DateFormat dt2)
{
    // COUNT TOTAL NUMBER OF DAYS BEFORE FIRST DATE 'dt1'
    // initialize count using years and day
    int n1 = dt1.y * 365 + dt1.d;
 
    // Add days for months in given date
    for (int i = 0; i < dt1.m - 1; i++)
        n1 += monthDays[i];
 
    // Since every leap year is of 366 days, add a day for every leap year
    n1 += countLeapYears(dt1);
 
    // COUNT TOTAL NUMBER OF DAYS BEFORE 'dt2'
    int n2 = dt2.y * 365 + dt2.d;
    for (int i = 0; i < dt2.m - 1; i++)
        n2 += monthDays[i];
    n2 += countLeapYears(dt2);
 
    // return difference between two counts
    return (n2 - n1);
}
