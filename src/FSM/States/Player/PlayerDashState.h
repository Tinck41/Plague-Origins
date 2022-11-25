#pragma once
#include "Screen/Entity.h"
#include "FSM/State.h"

class PlayerDashState :
	virtual public State
{
private:
	Entity& owner;

public:
	PlayerDashState(Entity& owner);

	void enter();
	void update(const float& dt);
	void exit();
};