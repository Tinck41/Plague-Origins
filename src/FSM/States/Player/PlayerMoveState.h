#pragma once
#include "Screen/Entity.h"
#include "FSM/State.h"

class PlayerMoveState :
	virtual public State
{
private:
	Entity& owner;

public:
	PlayerMoveState(Entity& owner);

	void enter();
	void update(const float& dt);
	void exit();
};