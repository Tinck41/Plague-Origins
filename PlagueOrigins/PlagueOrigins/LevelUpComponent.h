#pragma once

#include "PlayerCharacteristics.h"
#include "GameObjects.h"

class Player;
class Unit;

class LevelUpComponent
{
private:
	sf::RectangleShape& merchant;
	Unit* player;

	sf::Clock gameClock;
	sf::Time delay;
	sf::Time last;

	//interaction hitbox
	//TO-DO box2d
	sf::RectangleShape interactionTrigger;

	GameObjects& gObjects;
	PlayerCharacteristics* stats;

	bool interacting;

	void initTrigger();
	void increaseChar(unsigned int value, charName charName);
	void decreaseChar(unsigned int value, charName charName);
	void resetChars();
public:
	//Constructors/Destructors
	LevelUpComponent(sf::RectangleShape& merchant);
	//LevelUpComponent(sf::RectangleShape& merchant, Player& player);
	~LevelUpComponent();
	//Functions
	void interact();

	sf::RectangleShape getInteractionTrigger() { return interactionTrigger; }
};

