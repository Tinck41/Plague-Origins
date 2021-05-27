#pragma once
#include "Src/Screen/Entity.h"
#include "Src/FSM/State.h"

class BossIdleState :
	virtual public State
{
private:
	Entity& owner;
public:
	BossIdleState(Entity& owner);

	virtual void enter() override;
	virtual void update(const float& dt) override;
	virtual void exit() override;

};