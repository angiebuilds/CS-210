#include "ItemTracker.h"

#include <iostream>

using namespace std;

// Adds an item to the tracker, incrementing its frequency count
void ItemTracker::AddItem(const string& itemName) {
	itemFrequency[itemName]++;
}

// Retrieves the frequency of a specific item
int ItemTracker::GetItemFrequency(const string& itemName) const {
	auto item = itemFrequency.find(itemName);
	if (item != itemFrequency.end()) {
		return item->second;
	}
	return 0;
}


// gives other classes read-only access to the frequency map
const map<string, int>& ItemTracker::GetAllFrequencies() const {
	return itemFrequency; 
}

// Prints the frequency list of all items
void ItemTracker::PrintFrequencyList() const {
	for (const auto& item : itemFrequency) {
		cout << item.first << " " << item.second << endl;
	}
}

// Prints a histogram of item frequencies using asterisks
void ItemTracker::PrintHistogram() const {
	for (const auto& item : itemFrequency) {
		cout << item.first << " ";

		for (int i = 0; i < item.second; ++i) {
			cout << "*";
		}

		cout << endl;
	}
}