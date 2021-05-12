#include "stdafx.h"
#include "./NPCDogStates.h"

NPCDogMoveState::NPCDogMoveState(Entity& owner) :
	owner(owner)
{
}

void NPCDogMoveState::enter()
{
	std::cout << "MOVE\n";
	Animator& animator = owner.GetComponent<Animator>();
	Movement& movement = owner.GetComponent<Movement>();

	animator.previousAnimation = animator.currentAnimation;
	animator.currentAnimation = MOVE;
	animator.previousFaceDirection = animator.currentFaceDirection;
	animator.currentFaceDirection = movement.direction;
}

void NPCDogMoveState::update(const float& dt)
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
	//	PlayerSMcomponent& playerStates = owner.GetComponent<PlayerSMcomponent>();
	//	playerStates.currentState = playerStates.changeState(playerStates.currentState,
	//		new NPCDogAggroState(owner));
	//	std::cout << "";
	//}
	//else if (owner.getCombatComponent()->isInAttackRange())
	//{
	//	PlayerSMcomponent& playerStates = owner.GetComponent<PlayerSMcomponent>();
	//	playerStates.currentState = playerStates.changeState(playerStates.currentState,
	//		new NPCDogAttackState(owner));
	//	std::cout << "";
	//}
	else if (owner.GetComponent<Movement>().direction == sf::Vector2f(0, 0))
	{
		PlayerSMcomponent& playerStates = owner.GetComponent<PlayerSMcomponent>();
		playerStates.currentState = playerStates.changeState(playerStates.currentState,
			new NPCDogIdleState(owner));
		std::cout << "";
	}
	else
	{
		Animator& animator = owner.GetComponent<Animator>();
		Movement& movement = owner.GetComponent<Movement>();

		animator.previousAnimation = animator.currentAnimation;
		animator.currentAnimation = MOVE;
		animator.previousFaceDirection = animator.currentFaceDirection;
		animator.currentFaceDirection = movement.direction;
	}
}

void NPCDogMoveState::exit()
{
}
