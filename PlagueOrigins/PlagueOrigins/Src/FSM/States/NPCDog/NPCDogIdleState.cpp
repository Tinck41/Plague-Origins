#include "stdafx.h"
#include "./NPCDogStates.h"

NPCDogIdleState::NPCDogIdleState(Entity& owner) :
	owner(owner)
{
}

void NPCDogIdleState::enter()
{
	std::cout << "IDLE\n";
	Animator& animator = owner.GetComponent<Animator>();
	Movement& movement = owner.GetComponent<Movement>();

	animator.previousAnimation = animator.currentAnimation;
	animator.currentAnimation = IDLE;
}

void NPCDogIdleState::update(const float& dt)
{

	if (owner.GetComponent<Health>().curhealth <= 0)
	{
		PlayerSMcomponent& playerStates = owner.GetComponent<PlayerSMcomponent>();
		playerStates.currentState = playerStates.changeState(playerStates.currentState,
			new NPCDogDeathState(owner));
		std::cout << "";
	}
	//else if (owner.getCombatComponent()->isAggro())
	//{
	//	owner.getStateMachine()->changeState(new NPCDogAggroState(owner));
	//}
	else if (owner.GetComponent<Attack>().isAttacking)
	{
		PlayerSMcomponent& playerStates = owner.GetComponent<PlayerSMcomponent>();
		playerStates.currentState = playerStates.changeState(playerStates.currentState,
			new NPCDogAttackState(owner));
		std::cout << "";
	}
	else if (owner.GetComponent<Movement>().direction != sf::Vector2f(0, 0))
	{
		PlayerSMcomponent& playerStates = owner.GetComponent<PlayerSMcomponent>();
		playerStates.currentState = playerStates.changeState(playerStates.currentState,
			new NPCDogMoveState(owner));
		std::cout << "";
	}
	else
	{
		Animator& animator = owner.GetComponent<Animator>();
		Movement& movement = owner.GetComponent<Movement>();

		animator.previousAnimation = animator.currentAnimation;
		animator.currentAnimation = IDLE;
	}
}

void NPCDogIdleState::exit()
{
}