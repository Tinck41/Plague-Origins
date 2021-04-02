#pragma once
#include "NPCDog.h"
#include "NPCDogStates.h"

class NPCDogMoveState :
	virtual public State
{
private:
	FiniteStateMachine* stateMachine;
	NPCDog& owner;
public:
	NPCDogMoveState(NPCDog& owner);
	~NPCDogMoveState();

	void enter() override;
	void update(const float& dt) override;
	void exit() override;
};

