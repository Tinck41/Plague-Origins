#pragma once
#include "Screen/Entity.h"
#include "FSM/State.h"

class PlayerInteractState :
	virtual public State
{
private:
	Entity& owner;

public:
	PlayerInteractState(Entity& owner);

	void enter();
	void update(const float& dt);
	void exit();
};