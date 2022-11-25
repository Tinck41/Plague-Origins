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
	//if (owner.GetComponent<Health>().curhealth <= 0)
	//{
	//	SMcomponent& stateMachine = owner.GetComponent<SMcomponent>();
	//	stateMachine.currentState = stateMachine.changeState(stateMachine.currentState,
	//		new BishopDeathState(owner));
	//	std::cout << "";
	//}
	if (owner.GetComponent<Dialogue>().isInteracting == true)
	{
		SMcomponent& stateMachine = owner.GetComponent<SMcomponent>();
		stateMachine.currentState = stateMachine.changeState(stateMachine.currentState,
			new BishopInteractState(owner));
		std::cout << "";
	}
	//else
	//{
	//}
}

void BishopIdleState::exit()
{
}