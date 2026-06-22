#include "FileManager.h"
#include "ItemTracker.h"
#include "Menu.h"

#include <iostream>

using namespace std;

int main() {
	ItemTracker tracker;
	FileManager fileManager;
	Menu menu;

	//files required for the project
	const string inputFileName = "CS210_Project_Three_Input_File.txt";
	const string backupFileName = "frequency.dat";

	//loads items first so menu has data to work with
	if (!fileManager.LoadItemsFromFile(inputFileName, tracker)) {
		cout << "Program ended because the input file could not be loaded." << inputFileName << endl;
		return 1;
	}

	//creates backup file before user does anything with the data
	if (!fileManager.CreateBackupFile(backupFileName, tracker)) {
		cout << "Program ended because the backup file could not be created." << backupFileName << endl;
		return 1;
	}

	//runs the menu for user interaction
	menu.Run(tracker);

	return 0;
}