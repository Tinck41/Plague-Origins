#include "stdafx.h"
#include "./PlayerStates.h"

PlayerInteractState::PlayerInteractState(Entity& owner) :
	owner(owner)
{
}

void PlayerInteractState::enter()
{
	//std::cout << "DIALOGUE START\n";
	Animator& animator = owner.GetComponent<Animator>();

	animator.previousAnimation = animator.currentAnimation;
	animator.currentAnimation = IDLE;
}

void PlayerInteractState::update(const float& dt)
{
	if (owner.GetComponent<Health>().curhealth <= 0)
	{
		SMcomponent& stateMachine = owner.GetComponent<SMcomponent>();
		stateMachine.currentState = stateMachine.changeState(stateMachine.currentState,
			new PlayerDeathState(owner));
		std::cout << "";
	}
	else if (false)
	{
		SMcomponent& stateMachine = owner.GetComponent<SMcomponent>();
		stateMachine.currentState = stateMachine.changeState(stateMachine.currentState,
			new PlayerIdleState(owner));
		std::cout << "";
	}
	else
	{
		Animator& animator = owner.GetComponent<Animator>();

		animator.previousAnimation = animator.currentAnimation;
		animator.currentAnimation = IDLE;
	}
}

void PlayerInteractState::exit()
{
	std::cout << "DIALOGUE END\n";
}