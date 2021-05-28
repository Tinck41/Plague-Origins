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
		SMcomponent& playerStates = owner.GetComponent<SMcomponent>();
		playerStates.currentState = playerStates.changeState(playerStates.currentState,
			new PlayerDeathState(owner));
		std::cout << "";
	}
	else if (false)
	{
		SMcomponent& playerStates = owner.GetComponent<SMcomponent>();
		playerStates.currentState = playerStates.changeState(playerStates.currentState,
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