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
	std::cout << owner.getAnimator()->getArmatureDisplay()->getAnimation()->isCompleted() << "\n";
	this->owner.getAnimator()->setAnimation(animationName::ATTACK);
	this->owner.getCombatComponent()->attack();
	//this->owner.getCombat()->detect();
	//this->owner.getCombat()->applyDamage();
}

void NPCDogAttackState::update(const float& dt)
{
}

void NPCDogAttackState::exit()
{
}
