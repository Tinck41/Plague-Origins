#pragma once
#include "Src/Screen/Entity.h"
#include "Src/FSM/State.h"

class DogAttackState :
	virtual public State
{
private:
	Entity& owner;
public:
	DogAttackState(Entity& owner);

	virtual void enter() override;
	virtual void update(const float& dt) override;
	virtual void exit() override;
};

