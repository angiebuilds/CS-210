#include "FileManager.h"

#include <fstream>
#include <iostream>

using namespace std;

bool FileManager::LoadItemsFromFile(const string& inputFileName, ItemTracker& tracker) {
	ifstream inputFile(inputFileName);
	string itemName;

	// Check if the file was opened successfully
	if (!inputFile.is_open()) {
		cout << "Error: Could not open " << inputFileName << endl;
		return false;
	}
	
	// Read each line from the file and add it to the tracker
	while (inputFile >> itemName) {
		tracker.AddItem(itemName);
	}

	inputFile.close();
	return true;
}

bool FileManager::CreateBackupFile(const string& outputFileName, const ItemTracker& tracker) {
	ofstream outputFile(outputFileName);

	// Check if the file can be created/opened successfully
	if (!outputFile.is_open()) {
		cout << "Error: Could not create " << outputFileName << endl;
		return false;
	}

	// Write the item frequencies to the backup file
	for (const auto& item : tracker.GetAllFrequencies()) {
		outputFile << item.first << " " << item.second << endl;
	}

	outputFile.close();
	return true;
}