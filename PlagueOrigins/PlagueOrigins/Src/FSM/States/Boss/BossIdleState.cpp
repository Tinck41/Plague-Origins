#include "stdafx.h"
#include "BossStates.h"

BossIdleState::BossIdleState(Entity& owner) :
	owner(owner)
{
}

void BossIdleState::enter()
{
	std::cout << "Boss Idle State\n";
	Animator& animator = owner.GetComponent<Animator>();

	animator.previousAnimation = animator.currentAnimation;
	//animator.previousFaceDirection = animator.currentFaceDirection;
	//animator.currentFaceDirection = { .0f, 1.f };
	animator.currentAnimation = IDLE;
}

void BossIdleState::update(const float& dt)
{
	if (owner.GetComponent<Health>().curhealth <= 0)
	{
		SMcomponent& playerStates = owner.GetComponent<SMcomponent>();
		playerStates.currentState = playerStates.changeState(playerStates.currentState,
			new BossDeathState(owner));
		std::cout << "";
	}
	//TO-DO
	//else if (owner.GetComponent<Aggresion>().isAggresive)
	//{
	//	SMcomponent& playerStates = owner.GetComponent<SMcomponent>();
	//	playerStates.currentState = playerStates.changeState(playerStates.currentState,
	//		new BossAggroState(owner));
	//	std::cout << "";
	//}
	//else if (owner.GetComponent<Movement>().direction != sf::Vector2f(0, 0))
	//{
	//	SMcomponent& playerStates = owner.GetComponent<SMcomponent>();
	//	playerStates.currentState = playerStates.changeState(playerStates.currentState,
	//		new BossMoveState(owner));
	//	std::cout << "";
	//}
	else
	{
		//Animator& animator = owner.GetComponent<Animator>();

		//animator.previousAnimation = animator.currentAnimation;
		//animator.currentAnimation = IDLE;
	}
}

void BossIdleState::exit()
{
}