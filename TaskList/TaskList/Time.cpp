#pragma once
#include "Time.h"

using namespace std;

Time::Time()
{
	curr_time = time(NULL);
	localtime_s(&struct_time, &curr_time);
	hour = struct_time.tm_hour;
	day = struct_time.tm_mday;
	month = struct_time.tm_mon;
}

string Time::getTimeOfDay()
{
	string timeOfDay = (hour < 12) ? "Good Morning!" :
		(hour < 17) ? "Good Afternoon!" : "Good Evening!";

	return timeOfDay;
}

bool Time::withinTheWeek(int num)
{
	return (num >= day && num < (day + 7)) ? true : false;
}

bool Time::withinTheMonth(int num)
{
	return num == month;
}