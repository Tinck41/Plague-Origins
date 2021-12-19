#pragma once
#include "Screen/Entity.h"
#include "FSM/State.h"

class PlayerDeathState :
	virtual public State
{
private:
	Entity& owner;

public:
	PlayerDeathState(Entity& owner);

	void enter();
	void update(const float& dt);
	void exit();
};