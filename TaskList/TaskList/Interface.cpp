#include "Interface.h"
#include <iostream>
#include <ctime>

using namespace std;

Interface::Interface()
{
	choice = 0;
}

void Interface::clear()
{
	if(_WIN32)
		system("cls");
	else
		system("clear");
}

void Interface::reset()
{
	choice = 0;
}

string Interface::getTimeOfDay()
{
	time_t curr_time = time(NULL);
	struct tm struct_time;

	localtime_s(&struct_time, &curr_time);

	int hour = struct_time.tm_hour;

	string timeOfDay = (hour < 12) ? "Good Morning!" :
							 (hour < 17) ? "Good Afternoon!" : "Good Evening!";

	return timeOfDay;
}

void Interface::welcomeMessage()
{
	string timeOfDay = getTimeOfDay();

	cout << timeOfDay << endl;
}

void Interface::displayMenu()
{
	cout << "1.Add Task\n2.View Tasks\n3.Edit Task\n4.Remove Task\n5.Exit\n\nChoice: ";
}

void Interface::getChoice()
{
	reset();
	while (choice < 1 || choice > 5)
	{
		displayMenu();
		try
		{
			cin >> choice;
		}
		catch (...) {
			cout << "\nPlease enter a valid number between 1-5.\n";
			reset();
		}
	}
}

void Interface::runInterface()
{

	while (choice != 5)
	{
		welcomeMessage();
		getChoice();
		switch (choice)
		{
		case 1:
			tasks.saveTask("apples", "MON");
			break;
		case 2:
			tasks.displayTasks();
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		}
	}
}
