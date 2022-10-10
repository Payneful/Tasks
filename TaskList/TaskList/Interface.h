#pragma once
#include <string>
#include "tasks.h"

class Interface
{
private:
	int choice;
	Tasks tasks;

public:
	// Constructor
	Interface();

	// Resets choice = 0
	void reset();

	// Clears console screen
	void clear();

	// Simple welcome message based on time of day
	void welcomeMessage();

	// Returns the part of the day it is
	std::string getTimeOfDay();

	// Runs the interface program
	void runInterface();

	// Displays the menu options
	void displayMenu();

	// Gets the choice from user
	void getChoice();
};
