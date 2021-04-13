/*
	TO-DO:
	PlayerInventory is applied only on Player
	InventoryComponent is applied on every Unit descendant
	PlayerInventory ==> InventoryComponent
*/

#pragma once

class PlayerInventory
{
private:
	int essence;
public:
	//Constructors
	PlayerInventory();
	~PlayerInventory();
	//Functions
	bool setEssence(int value);
	void grantEssence(int baseCost);
	//Getters
	int getEssence();
};

