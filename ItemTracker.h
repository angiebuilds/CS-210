#ifndef ITEM_TRACKER_H
#define ITEM_TRACKER_H

#include <map>
#include <string>


using namespace std;

class ItemTracker {
private:
	map<string, int> itemFrequency;

public:
	void AddItem(const string& itemName);
	int GetItemFrequency(const string& itemName) const;
	const map<string, int>& GetAllFrequencies() const;
	void PrintFrequencyList() const;
	void PrintHistogram() const;
};

#endif