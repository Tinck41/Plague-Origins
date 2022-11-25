#pragma once
#include "Screen/Entity.h"
#include "FSM/State.h"

class DogIdleState :
	virtual public State
{
private:
	Entity& owner;

public:
	DogIdleState(Entity& owner);

	void enter();
	void update(const float& dt);
	void exit();
};