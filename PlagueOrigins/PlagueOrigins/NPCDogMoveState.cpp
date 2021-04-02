#include "stdafx.h"
#include "NPCDogMoveState.h"

NPCDogMoveState::NPCDogMoveState(NPCDog& owner) :
	owner(owner)
{
	stateMachine = owner.getStateMachine();
}

NPCDogMoveState::~NPCDogMoveState()
{
}

void NPCDogMoveState::enter()
{
	std::cout << "Dog Move State\n";
	this->owner.getAnimator()->setAnimation(animationName::MOVE, owner.getPatrol()->getDirection());
}

void NPCDogMoveState::update(const float& dt)
{
	if (owner.getCombatComponent()->isAggro())
	{
		owner.getStateMachine()->changeState(new NPCDogAggroState(owner));
	}
	else if (owner.getCombatComponent()->isInAttackRange())
	{
		owner.getStateMachine()->changeState(new NPCDogAttackState(owner));
	}
	else if (owner.getPatrol()->getDirection() == sf::Vector2f(0, 0))
	{
		stateMachine->changeState(new NPCDogIdleState(owner));
	}
	else if (owner.getCombatComponent()->isDead())
	{
		owner.getStateMachine()->changeState(new NPCDogDeathState(owner));
	}
	else
	{
		owner.getMover()->move(dt, owner.getPatrol()->getDirection());
		this->owner.getAnimator()->setAnimation(animationName::MOVE, this->owner.getPatrol()->getDirection());
	}
}

void NPCDogMoveState::exit()
{
}
