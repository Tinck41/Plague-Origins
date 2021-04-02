#include "stdafx.h"
#include "NPCDogAttackState.h"

NPCDogAttackState::NPCDogAttackState(NPCDog& owner) :
	owner(owner)
{
	stateMachine = owner.getStateMachine();
}

NPCDogAttackState::~NPCDogAttackState()
{
	stateMachine = NULL;
	delete stateMachine;
}

void NPCDogAttackState::enter()
{
	std::cout << "Dog Attack State\n";
	std::cout << owner.getAnimator()->getArmatureDisplay()->getAnimation()->isCompleted() << "\n";
	this->owner.getAnimator()->setAnimation(animationName::ATTACK);
	this->owner.getCombatComponent()->attack();
}

void NPCDogAttackState::update(const float& dt)
{
	if (owner.getAnimator()->getArmatureDisplay()->getAnimation()->isCompleted())
	{
		if (owner.getCombatComponent()->isInAttackRange())
		{
			owner.getStateMachine()->changeState(new NPCDogAttackState(owner));
		}
		else
		{
			owner.getStateMachine()->changeState(new NPCDogAggroState(owner));
		}
	}
}

void NPCDogAttackState::exit()
{
}
