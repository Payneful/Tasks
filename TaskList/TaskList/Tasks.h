#pragma once

#include <string>
#include "json.h"
#include "Time.h"

using namespace std;
using json = nlohmann::json;

/***********************************************
 * TASKS
 * This class will hold the different tasks
 * from the user that they wish to see later.
 **********************************************/
class Tasks
{
private:
	json tasks;
	string filename;
	Time time;

public:
	// Constructors
	Tasks();
	Tasks(string file);

	// Getters
	json getTasks();

	// Display all tasks
	void displayTasks();

	// Reads the current tasks in the file
	void updateTasks(string file);

	// Saves task to json file
	void saveTask(string task);

	// Edits a task
	void editTask();

	// Clears a task
	void clearTask();

	// Sets values to be in order
	void resetValues();
};
