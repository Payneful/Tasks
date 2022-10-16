#pragma once
#include <string>
#include "tasks.h"

class Interface
{
private:
	int choice;
	Tasks tasks;
	Time time;

public:
	// Constructor
	Interface();

	// Resets choice = 0
	void reset();

	// Clears console screen
	void clear();

	// Simple welcome message based on time of day
	void welcomeMessage();

	// Runs the interface program
	void runInterface();

	// Displays the menu options
	void displayMenu();

	// Gets the task to be saved
	string getTaskToSave();

	// Gets the choice from user
	void getChoice();
};
