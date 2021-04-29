#include "stdafx.h"
#include "FSM.h"
#include "Src/Screen/Entity.h"

void FSM::changeState(State* currentState, State* newState)
{
	if (currentState != nullptr)
	{
		currentState->exit();
		delete currentState;
	}

	currentState = newState;

	currentState->enter();
}

void FSM::update(entt::registry& reg, const float& dt)
{
	auto view = reg.view<PlayerStates>();

	for (auto entity : view)
	{
		PlayerStates& stateMachine = reg.get<PlayerStates>(entity);

		if (stateMachine.currentState != nullptr)
		{
			stateMachine.currentState->update(dt);
		}
	}
}
