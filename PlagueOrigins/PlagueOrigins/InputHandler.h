#pragma once

#include "PlayerStates.h"

class InputHandler
{
private:
	sf::Vector2f direction;

	unsigned globalState = 0;
	unsigned localState = 1;

	bool isMoving = false;

	void getMovementInput();
	void getDashInput();
	void getAttackInput();
	void getSpellInput();
public:
	sf::Vector2f getDirection() { return this->direction; }
	unsigned getGlobalState() { return this->globalState; }
	unsigned getLocalState() { return this->localState; }

	void update();
};

