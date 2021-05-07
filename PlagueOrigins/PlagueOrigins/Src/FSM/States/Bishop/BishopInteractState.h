#pragma once
#include "Src/Screen/Entity.h"
#include "Src/FSM/State.h"

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