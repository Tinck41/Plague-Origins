#include "stdafx.h"
#include "./BishopStates.h"

BishopInteractState::BishopInteractState(Entity& owner) :
	owner(owner)
{
}

void BishopInteractState::enter()
{
	std::cout << "BISHOP INTERACT\n";
	Animator& animator = owner.GetComponent<Animator>();

	animator.previousAnimation = animator.currentAnimation;
	animator.currentAnimation = INTERACT;
}

void BishopInteractState::update(const float& dt)
{
	//if (owner.GetComponent<Health>().curhealth <= 0)
	//{
	//	SMcomponent& smComponent = owner.GetComponent<SMcomponent>();
	//	smComponent.currentState = smComponent.changeState(smComponent.currentState,
	//		new BishopDeathState(owner));
	//	std::cout << "";
	//}
	//END OF INTERACTION
	if (owner.GetComponent<Dialogue>().isInteracting == false)
	{
		SMcomponent& smComponent = owner.GetComponent<SMcomponent>();
		smComponent.currentState = smComponent.changeState(smComponent.currentState,
			new BishopIdleState(owner));
		std::cout << "";
	}
}

void BishopInteractState::exit()
{
	std::cout << "bishop end of interact state\n";
}