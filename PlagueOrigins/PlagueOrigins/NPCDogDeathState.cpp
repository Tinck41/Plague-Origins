#include "stdafx.h"
#include "NPCDogDeathState.h"

NPCDogDeathState::NPCDogDeathState(NPCDog& owner) :
	owner(owner)
{
	stateMachine = owner.getStateMachine();
}

NPCDogDeathState::~NPCDogDeathState()
{
	stateMachine = NULL;
	delete stateMachine;
}

void NPCDogDeathState::enter()
{
	std::cout << owner.getAnimator()->getArmatureDisplay()->getAnimation()->isCompleted() << "\n";
	this->owner.getAnimator()->setAnimation(animationName::DIE);
}

void NPCDogDeathState::update(const float& dt)
{
}

void NPCDogDeathState::exit()
{
}
