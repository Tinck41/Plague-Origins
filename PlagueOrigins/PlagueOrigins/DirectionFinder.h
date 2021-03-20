#pragma once
#include "InputBooleans.h"

/*
	class that finds direction
	and switch localState based on input
*/
class DirectionFinder
{
private:
	sf::Vector2f direction;

	unsigned localState = 1;

	bool isMoving = false;

	void getMovementInput();
	//void getDashInput();
	//void getAttackInput();
	//void getSpellInput();
public:
	sf::Vector2f getDirection() { return this->direction; }
	unsigned getLocalState() { return this->localState; }

	void update();
};

