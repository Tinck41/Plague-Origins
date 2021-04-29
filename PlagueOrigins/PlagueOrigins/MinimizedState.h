// #pragma once
// #include "InventoryStates.h"
// #include "InventoryComponent.h"

// class MinimizedState : virtual public State
// {
// private:
// 	FiniteStateMachine* stateMachine;
// 	InventoryComponent& owner;
// public:
// 	MinimizedState(InventoryComponent& owner);
// 	~MinimizedState();

// 	void enter() override;
// 	void update(const float& dt) override;
// 	void exit() override;
// };