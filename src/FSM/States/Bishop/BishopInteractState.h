#pragma once
#include "Screen/Entity.h"
#include "FSM/State.h"

class BishopInteractState :
	virtual public State
{
private:
	Entity& owner;

public:
	BishopInteractState(Entity& owner);

	void enter();
	void update(const float& dt);
	void exit();
};