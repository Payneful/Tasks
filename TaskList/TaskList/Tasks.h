#pragma once

#include <string>
#include "json.h"

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
	void saveTask(string task, string day);
};