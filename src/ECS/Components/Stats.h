#pragma once

struct Stats
{
	//int VIT, int END, int STR, int AGI, int INT
	Stats(std::vector<int> stats)
	{
		VIT = stats[0];
		END = stats[1];
		STR = stats[2];
		AGI = stats[3];
		INT = stats[4];
		upgradeCost = -950 + (VIT + END + STR + AGI) * 25;
	}
    //vitality - max hp
	//endurance - max stamina
	//strength - attack damage
	//agility - armor & dash cd
	//intelligence - skill damage(TO-DO?)
	//humanity - karma like affects ending(TO-DO??)
	int VIT;
	int END;
	int STR;
	int AGI;
	int INT;
	int upgradeCost;
};