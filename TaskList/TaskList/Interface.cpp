#include "Interface.h"
#include <iostream>

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

void Interface::welcomeMessage()
{
	string timeOfDay = time.getTimeOfDay();

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
		reset();
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

string Interface::getTaskToSave()
{
	string task;
	cout << "Enter a new task: ";
	cin.ignore();
	cin.clear();
	getline(cin, task);

	return task;
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
		{
			clear();
			string task = getTaskToSave();
			tasks.saveTask(task);
			clear();
			break;
		}
		case 2:
		{
			clear();
			cout << "Tasks: " << endl;
			tasks.displayTasks();
			cout << "\n\n";
			break;
		}
		case 3:
		{
			clear();
			tasks.editTask();
			clear();
			break;
		}
		case 4:
		{
			clear();
			tasks.clearTask();
			clear();
			break;
		}
		case 5:
		{
			clear();
			cout << "\n\nSee you soon!\n\n";
			break;
		}
		}
	}
}
