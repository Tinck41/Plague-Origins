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
	this->owner.getAnimator()->setAnimation(animationName::MOVE, owner.getPatrol()->getDirection());
}

void NPCDogMoveState::update(const float& dt)
{
	if (owner.getCombatComponent()->isTriggered())
	{
		owner.getStateMachine()->changeState(new NPCDogAttackState(owner));
	}
	else if (owner.getPatrol()->getDirection() == sf::Vector2f(0, 0))
	{
		this->stateMachine->changeState(new NPCDogIdleState(this->owner));
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
