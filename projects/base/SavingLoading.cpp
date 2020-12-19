#pragma once
#include "SavingLoading.h"
#include "example.h"

void SavingLoading::Save(Tile* tiles)
{
	{
		std::ofstream myfile;
		myfile.open("map.data");

		for (size_t i = 0; i < TILES_ARRAZY_SIZE; i++)
		{
			myfile << tiles[i].id << ", ";
		}

		myfile.close();
	}
}
void SavingLoading::Loading()
{
	{
		std::string line;
		std::ifstream myfile("map data");

		if (myfile.is_open())
		{
			int ic = 0;
			std::getline(myfile, line);

			for (size_t i = 0; i < 10; i++)
			{
				ic = line.find(',', ic + 1);
				std::string ss = line.substr(ic - 1, (line.find(',', ic + 1)) - ic - 2);
				std::cout << ss << std::endl;
			}
			myfile.close();
		}
		else
			std::cout << "Unable to open file";
	}

}