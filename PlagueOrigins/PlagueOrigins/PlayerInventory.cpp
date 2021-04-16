#include "stdafx.h"
#include "PlayerInventory.h"

PlayerInventory::PlayerInventory()
{
	srand(time(NULL));
	essence = rand() % 50 + 20;
	std::cout << "Init essence: " << essence << "\n";
}

PlayerInventory::~PlayerInventory()
{
}

bool PlayerInventory::setEssence(int value)
{
	if (essence + value >= 0)
	{
		essence += value;
		std::cout << "Essence: " << essence << "\n";
		return true;
	}
	std::cout << "Not enough essence.\n";
	return false;
}

void PlayerInventory::grantEssence(int baseCost)
{
	int value = rand() % baseCost*1.5 + baseCost/2;
	std::cout << "Added essence: " << value << "\n";
	setEssence(value);
}

int PlayerInventory::getEssence()
{
	return essence;
}
