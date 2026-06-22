#ifndef MENU_H
#define MENU_H

#include "ItemTracker.h"

class Menu {
private:
	void PrintMenu() const;
	int GetValidatedChoice() const;
	void SearchForItem(const ItemTracker& tracker) const;

public:
	void Run(ItemTracker& tracker) const;
};

#endif