#pragma once
#include "Screen/Entity.h"
#include "FSM/State.h"

class BossDeathState :
	virtual public State
{
private:
	Entity& owner;

	sf::Clock gameClock;
	sf::Time delay;
	sf::Time now;
	sf::Time last;
public:
	BossDeathState(Entity& owner);

	virtual void enter() override;
	virtual void update(const float& dt) override;
	virtual void exit() override;

};