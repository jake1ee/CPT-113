#include "Date.h"
#include <iostream>
#include <string>

Date::Date()
{
	CheckIn=CheckOut={0,0,0};
}

Date::Date(int d1, int m1, int y1, int d2, int m2, int y2) //alternate constructor
{
	CheckIn.d = d1;
	CheckIn.m = m1;
	CheckIn.y = y1;
	CheckOut.d = d2;
	CheckOut.m = m2;
	CheckOut.y = y2;
	checkValidity();
}

void Date::setDate(int d1, int m1, int y1, int d2, int m2, int y2) //set values of dates
{
	CheckIn.d = d1;
	CheckIn.m = m1;
	CheckIn.y = y1;
	CheckOut.d = d2;
	CheckOut.m = m2;
	CheckOut.y = y2;
    checkValidity();
}

void Date::checkValidity()
{
    if (CheckIn.m > 12)
    {
        CheckIn.y++;
    }
    while (CheckIn.d > monthDays[CheckIn.m - 1])
    {
        CheckIn.d -= monthDays[CheckIn.m - 1];
        CheckIn.m++;
    }

    if (CheckOut.m > 12)
    {
        CheckOut.y++;
    }
    while (CheckOut.d > monthDays[CheckOut.m - 1])
    {
        CheckOut.d -= monthDays[CheckOut.m - 1];
        CheckOut.m++;
    }
}

int Date::getNumDays()
{
	return NumDays;
}

// This function counts number of
// leap years before the given date
int Date::countLeapYears(DateFormat d)
{
    checkValidity();
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
int Date::getDifference(DateFormat CheckIn, DateFormat CheckOut)
{
    checkValidity();
    // COUNT TOTAL NUMBER OF DAYS BEFORE FIRST DATE 'CheckIn'
    // initialize count using years and day
    int n1 = CheckIn.y * 365 + CheckIn.d;
 
    // Add days for months in given date
    for (int i = 0; i < CheckIn.m - 1; i++)
        n1 += monthDays[i];
 
    // Since every leap year is of 366 days, add a day for every leap year
    n1 += countLeapYears(CheckIn);
 
    // COUNT TOTAL NUMBER OF DAYS BEFORE 'CheckOut'
    int n2 = CheckOut.y * 365 + CheckOut.d;
    for (int i = 0; i < CheckOut.m - 1; i++)
        n2 += monthDays[i];
    n2 += countLeapYears(CheckOut);
 
    // return difference between two counts
    return (n2 - n1);
}
