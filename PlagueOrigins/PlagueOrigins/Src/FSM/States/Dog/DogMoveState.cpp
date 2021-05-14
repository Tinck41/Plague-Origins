#include "stdafx.h"
#include "./DogStates.h"

DogMoveState::DogMoveState(Entity& owner) :
	owner(owner)
{
}

void DogMoveState::enter()
{
	std::cout << "MOVE\n";
	Animator& animator = owner.GetComponent<Animator>();
	Movement& movement = owner.GetComponent<Movement>();

	animator.previousAnimation = animator.currentAnimation;
	animator.currentAnimation = MOVE;
	animator.previousFaceDirection = animator.currentFaceDirection;
	animator.currentFaceDirection = movement.direction;
}

void DogMoveState::update(const float& dt)
{
	if (owner.GetComponent<Health>().curhealth <= 0)
	{
		PlayerSMcomponent& playerStates = owner.GetComponent<PlayerSMcomponent>();
		playerStates.currentState = playerStates.changeState(playerStates.currentState,
			new DogDeathState(owner));
		std::cout << "";
	}
	//else if (owner.getCombatComponent()->isAggro())
	//{
	//	PlayerSMcomponent& playerStates = owner.GetComponent<PlayerSMcomponent>();
	//	playerStates.currentState = playerStates.changeState(playerStates.currentState,
	//		new DogAggroState(owner));
	//	std::cout << "";
	//}
	//else if (owner.getCombatComponent()->isInAttackRange())
	//{
	//	PlayerSMcomponent& playerStates = owner.GetComponent<PlayerSMcomponent>();
	//	playerStates.currentState = playerStates.changeState(playerStates.currentState,
	//		new DogAttackState(owner));
	//	std::cout << "";
	//}
	else if (owner.GetComponent<Movement>().direction == sf::Vector2f(0, 0))
	{
		PlayerSMcomponent& playerStates = owner.GetComponent<PlayerSMcomponent>();
		playerStates.currentState = playerStates.changeState(playerStates.currentState,
			new DogIdleState(owner));
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

void DogMoveState::exit()
{
}
