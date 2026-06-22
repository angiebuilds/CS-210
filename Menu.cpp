#include "Menu.h"

#include <iostream>
#include <limits>
#include <string>

using namespace std;

// Displays menu options
void Menu::PrintMenu() const {
	cout << endl;
	cout << "Corner Grocer Item Tracking Menu" << endl;
	cout << "1. Search for an item frequency" << endl;
	cout << "2. Print frequency list" << endl;
	cout << "3. Print frequency histogram" << endl;
	cout << "4. Exit" << endl;
	cout << "Enter your choice: ";
}

// Validates user's menu choice and ensures it's an integer
int Menu::GetValidatedChoice() const {
	int menuChoice;

	
	while (!(cin >> menuChoice)) {
		cout << "Invalid input. Pease enter a number from 1 to 4: ";
		
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	return menuChoice;
}

// Prompts user to enter item name and displays how many times it was purchased
void Menu::SearchForItem(const ItemTracker& tracker) const {
	string itemName;

	cout << "Enter the item name: ";
	cin >> itemName;

	//capitalize first letter of input to match stored item names
	if (!itemName.empty()) itemName[0] = toupper(itemName[0]);

	cout << itemName << " was purchased "
		<< tracker.GetItemFrequency(itemName) << " time(s)." << endl;
}

//	Main loop that runs menu and processes user choices until they exit
void Menu::Run(ItemTracker& tracker) const {
	int menuChoice = 0;

	while (menuChoice != 4) {
		PrintMenu();
		menuChoice = GetValidatedChoice();

		switch (menuChoice) {
		case 1:
			SearchForItem(tracker);
			break;

		case 2:
			tracker.PrintFrequencyList();
			break;

		case 3:
			tracker.PrintHistogram();
			break;

		case 4:
			cout << "Exiting the program. Goodbye!" << endl;
			break;

		default:
			cout << "Invalid choice. Please enter a number from 1 to 4." << endl;
			break;
		}
	}
}