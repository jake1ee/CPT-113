#include "Date.h"
#include <iostream>
#include <string>

//Constructor
Date::Date()
{
	CheckIn=CheckOut={0,0,0};
    NumDays = 1;
}

//Destructor
Date::~Date()
{
    CheckIn = CheckOut = { 0,0,0 };
    NumDays = 1;
}

//ALternate constructor
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

//This function sets check in and check out dates
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

//This function checks the validity of dates
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
    while (CheckOut.d > monthDays[CheckOut.m ])
    {
        CheckOut.d -= monthDays[CheckOut.m - 1];
        CheckOut.m++;
    }
}

//This function calls function to count number of days
//stayed in dorm and return it
int Date::getNumDays()
{
    getDifference(CheckIn, CheckOut);
	return NumDays;
}

//// This function counts number of
//// leap years before the given date
//int Date::countLeapYears(DateFormat d)
//{
//    checkValidity();
//    int years = d.y;
// 
//    // Check if the current year needs to be
//    //  considered for the count of leap years
//    // or not
//    if (d.m <= 2)
//        years--;
// 
//    // An year is a leap year if it is a multiple of 4,
//    // multiple of 400 and not a multiple of 100.
//    return (years / 4) - (years / 100) + (years / 400);
//}
 
// This function returns number of days between two given dates
void Date::getDifference(DateFormat CheckIn, DateFormat CheckOut)
{
    checkValidity();
    if (CheckOut.y > CheckIn.y)
    {
        cout << "InYear" << endl;
        NumDays += monthDays[CheckIn.m - 1] - CheckIn.d;
        for (int i = 0; i < CheckOut.m - 1; i++)
        {
            NumDays += monthDays[i];
        }
        for (int i = CheckIn.m; i < 12; i++)
        {
            NumDays += monthDays[i];
        }
    }
    else if (CheckOut.y == CheckIn.y)
    {
        if (CheckIn.m == CheckOut.m)
        {
            NumDays = CheckOut.d - CheckIn.d;
        }
        else if (CheckOut.m > CheckIn.m)
        {
            for (int i = CheckIn.m ; i < CheckOut.m - 1; i++)
            {
                NumDays += monthDays[i];
            }
            NumDays =   NumDays+CheckOut.d - CheckIn.d;
        }
        else
        {
            cout << "Check out month is smaller than check in month" << endl;
            exit(EXIT_FAILURE);
        }
    }   
    else
    {
        cout << "Check Out Year Error!" << endl;
        exit(EXIT_FAILURE);
    }
    }
    
 
   

