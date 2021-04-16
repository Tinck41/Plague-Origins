#pragma once
#include "PlayerAnimationStates.h"


class PlayerCharacteristics
{
private:
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
	unsigned int HUM;

public:
	PlayerCharacteristics();
	//void setChar(std::string charName);
	void setChar(unsigned int value, charName charName);
	//unsigned int getChar(std::string charName);
	int getChar(charName charName);
};

