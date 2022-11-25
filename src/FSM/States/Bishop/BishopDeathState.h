#pragma once
#include "Screen/Entity.h"
#include "FSM/State.h"

class BishopDeathState :
	virtual public State
{
private:
	Entity& owner;

	sf::Clock gameClock;
	sf::Time delay;
	sf::Time now;
	sf::Time last;

public:
	BishopDeathState(Entity& owner);

	void enter();
	void update(const float& dt);
	void exit();
};