#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "ItemTracker.h"

#include <string>

using namespace std;

class FileManager {
public:
	bool LoadItemsFromFile(const string& inputFileName, ItemTracker& tracker);
	bool CreateBackupFile(const string& outputFileName, const ItemTracker& tracker);
};

#endif