#include "Date.h"

void Date::checkValidity()
{
	if (day>28)
	{
		month += day % 28;
		day /= 28;
	}
}