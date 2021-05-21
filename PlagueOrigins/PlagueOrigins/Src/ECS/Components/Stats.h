#pragma once

struct Stats
{
	//int VIT, int END, int STR, int AGI, int INT
	Stats(std::vector<int> stats)
	{
		this->VIT = stats[0];
		this->END = stats[1];
		this->STR = stats[2];
		this->AGI = stats[3];
		this->INT = stats[4];
	}
    //vitality - max hp
	//endurance - max stamina
	//strength - attack damage
	//agility - armor & dash cd
	//intelligence - skill damage(TO-DO?)
	//humanity - karma like affects ending(TO-DO??)
	unsigned int VIT;
	unsigned int END;
	unsigned int STR;
	unsigned int AGI;
	unsigned int INT;
};