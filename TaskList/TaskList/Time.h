#pragma once
#include <string>
#include <ctime>

class Time
{
private:
	time_t curr_time;
	struct tm struct_time;
	int hour;
	int day;
	int month;

public:
	Time();
	std::string getTimeOfDay();
	int getDay()	{ return day;	 }
	int getMonth() { return month; }
	int getHour()	{ return hour;	 }
	bool withinTheWeek(int num);
	bool withinTheMonth(int num);
	std::string getMD() { return (std::to_string(month) + "/" + std::to_string(day)); }
};
