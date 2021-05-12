#pragma once
#include "Src/Screen/Entity.h"
#include "Src/FSM/State.h"

class NPCDogDeathState :
	virtual public State
{
private:
	Entity& owner;

	sf::Clock gameClock;
	sf::Time delay;
	sf::Time now;
	sf::Time last;

public:
	NPCDogDeathState(Entity& owner);

	virtual void enter() override;
	virtual void update(const float& dt) override;
	virtual void exit() override;
};

