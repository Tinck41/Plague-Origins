#pragma once
#include "InventoryStates.h"
#include "InventoryComponent.h"

class UnfoldedState : virtual public State
{
private:
	FiniteStateMachine* stateMachine;
	InventoryComponent& owner;
public:
	UnfoldedState(InventoryComponent& owner);
	~UnfoldedState();

	void enter() override;
	void update(const float& dt) override;
	void exit() override;
};

