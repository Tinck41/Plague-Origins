#pragma once

#include "NPCDog.h"
#include "NPCDogStates.h"

class NPCDogAttackState :
	virtual public State
{
private:
	FiniteStateMachine* stateMachine;
	NPCDog& owner;

	sf::Clock gameClock;
	sf::Time delay;
	sf::Time now;
	sf::Time last;
public:
	NPCDogAttackState(NPCDog& owner);
	~NPCDogAttackState();

	virtual void enter() override;
	virtual void update(const float& dt) override;
	virtual void exit() override;
};

