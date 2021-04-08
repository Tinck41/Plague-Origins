#pragma once

#include "PlayerCharacteristics.h"

class Player;
class Unit;

class LevelUpComponent
{
private:
	sf::RectangleShape& merchant;

	//interaction hitbox
	//TO-DO box2d
	sf::RectangleShape interactionTrigger;

	Player& player;
	PlayerCharacteristics* stats;
	void initTrigger();
	void increaseChar(unsigned int value, charName charName);
	void decreaseChar(unsigned int value, charName charName);
	void resetChars();
public:
	LevelUpComponent(sf::RectangleShape& merchant, Player& player);
	~LevelUpComponent();

};

