#pragma once
#include "Src/Screen/Entity.h"
#include "Src/FSM/State.h"

class DogMoveState :
	virtual public State
{
private:
	Entity& owner;
public:
	DogMoveState(Entity& owner);

	void enter() override;
	void update(const float& dt) override;
	void exit() override;
};

