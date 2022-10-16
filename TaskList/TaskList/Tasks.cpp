#include <fstream>
#include <iostream>
#include "Tasks.h"

using namespace std;

/***********************************************
 * GET TASKS
 * Returns the current tasks.
 **********************************************/
Tasks::Tasks()
{
	updateTasks("tasks.json");
}

/***********************************************
 * GET TASKS
 * Returns the current tasks.
 **********************************************/
Tasks::Tasks(string file)
{
	filename = file;
	updateTasks(file);
}

/***********************************************
 * GET TASKS
 * Returns the current tasks.
 **********************************************/
json Tasks::getTasks()
{
	return tasks;
}

/***********************************************
 * READ FILE TASKS
 * Reads the tasks from the file
 **********************************************/
void Tasks::updateTasks(string file)
{
	ifstream mtasks(file);
	tasks = json::parse(mtasks);
}

/***********************************************
 * DISPLAY TASKS
 * Reads the tasks from the file
 **********************************************/
void Tasks::displayTasks()
{
	int count = 0;

	for (json::iterator it = tasks.begin(); it != tasks.end(); ++it)
	{
		cout << count << ". " << it.value() << endl;
		count += 1;
	}
}

/***********************************************
 * SAVE TASK
 * Saves a new task to the json
 ***********************************************/
void Tasks::saveTask(string task)
{
	tasks["task" + to_string(tasks.size())] = task;
	ofstream f(filename);
	f << tasks;
	f.flush();
}

/***********************************************
 * EDIT TASK
 * Allows you to edit a task
 ***********************************************/
void Tasks::editTask()
{
	int taskNum = 0;
	string task = "";

	cout << "Which task would you like to edit?\n";
	displayTasks();
	cout << "Number: ";
	cin >> taskNum;
	cout << "\nWhat would you like to change it to?" << endl;
	cin >> task;
	cout << "\nTaskNum " << taskNum << " is now: " << task << "\n\n";
	tasks["task" + to_string(taskNum)] = task;
	cin.ignore();
	cin.clear();
}

/***********************************************
 * RESET VALUES
 * Goes through and resets order of numbers
 ***********************************************/
void Tasks::resetValues()
{
	int count = 0;
	json j;

	for (json::iterator it = tasks.begin(); it != tasks.end(); ++it)
	{
		j["task" + to_string(count)] = it.value();
		count += 1;
	}
	tasks = j;
}

/***********************************************
 * CLEAR TASK
 * Clears a chosen task
 ***********************************************/
void Tasks::clearTask()
{
	int taskNum = 0;

	cout << "Which task would you like to clear?\n";
	displayTasks();
	cout << "Number: ";
	cin >> taskNum;
	cout << "\nTaskNum " << taskNum << " has been cleared" << "\n\n";
	tasks.erase("task" + to_string(taskNum));
	cin.ignore();
	cin.clear();
	resetValues();
}