#pragma once

#include "NPCDog.h"
#include "NPCDogStates.h"

class NPCDogDeathState :
	virtual public State
{
private:
	FiniteStateMachine* stateMachine;
	NPCDog& owner;
public:
	NPCDogDeathState(NPCDog& owner);
	~NPCDogDeathState();

	virtual void enter() override;
	virtual void update(const float& dt) override;
	virtual void exit() override;
};

