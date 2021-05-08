#pragma once
#include "Src/Screen/Entity.h"
#include "Src/FSM/State.h"

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

