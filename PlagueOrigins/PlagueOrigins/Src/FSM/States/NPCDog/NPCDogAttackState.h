#pragma once

#include "NPCDog.h"
#include "NPCDogStates.h"

class NPCDogAttackState :
	virtual public State
{
private:
	Entity& owner;
public:
	NPCDogAttackState(Entity& owner);

	virtual void enter() override;
	virtual void update(const float& dt) override;
	virtual void exit() override;
};

