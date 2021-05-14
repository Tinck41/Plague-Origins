#include "stdafx.h"
#include "./BishopStates.h"

BishopIdleState::BishopIdleState(Entity& owner) :
	owner(owner)
{
}

void BishopIdleState::enter()
{
	std::cout << "BISHOP IDLE\n";
	Animator& animator = owner.GetComponent<Animator>();

	animator.previousAnimation = animator.currentAnimation;
	animator.currentAnimation = IDLE;

}

void BishopIdleState::update(const float& dt)
{
	if (owner.GetComponent<Health>().curhealth <= 0)
	{
		PlayerSMcomponent& playerStates = owner.GetComponent<PlayerSMcomponent>();
		playerStates.currentState = playerStates.changeState(playerStates.currentState,
			new BishopDeathState(owner));
		std::cout << "";
	}
	else if (owner.GetComponent<Interact>().isInteracting == true)
	{
		PlayerSMcomponent& playerStates = owner.GetComponent<PlayerSMcomponent>();
		playerStates.currentState = playerStates.changeState(playerStates.currentState,
			new BishopInteractState(owner));
		std::cout << "";
	}
	else
	{
	}
}

void BishopIdleState::exit()
{
}