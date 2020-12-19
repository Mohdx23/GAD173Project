#pragma once
#include "app.h"
#include "Tile.h"
#include <fstream>

class SavingLoading
{
public:
	void Save(Tile* tiles);
	void Loading();
};
