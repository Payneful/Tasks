#include <fstream>
#include <iostream>
#include "Tasks.h"

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
	cout << tasks;
}

/***********************************************
 * SAVE TASK
 * Saves a new task to the json
 ***********************************************/
void Tasks::saveTask(string task, string day)
{
	tasks[task] = day;
}

