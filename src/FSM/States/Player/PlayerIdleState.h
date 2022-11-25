#pragma once
#include "Screen/Entity.h"
#include "FSM/State.h"

class PlayerIdleState :
	virtual public State
{
private:
	Entity& owner;

public:
	PlayerIdleState(Entity& owner);
	
	void enter();
	void update(const float& dt);
	void exit();
};