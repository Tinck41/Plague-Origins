#pragma once

enum ITEM_TYPE
{
	RING,
	CONSUMABLE
};

struct Item 
{
	Item(std::string name, ITEM_TYPE type)
	{
		this->name = name;
		this->type = type;
	}

	std::string name;
	ITEM_TYPE type;
	bool isEquiped = false;
};