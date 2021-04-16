#include "stdafx.h"
#include "NPCDogDeathState.h"

NPCDogDeathState::NPCDogDeathState(NPCDog& owner) :
	owner(owner)
{
	stateMachine = owner.getStateMachine();
	delay = sf::seconds(2.f);
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

	//Timer
	last = gameClock.getElapsedTime();
}

void NPCDogDeathState::update(const float& dt)
{
	now = gameClock.getElapsedTime();
	if (now - last >= delay)
	{
		owner.setActiveStatus(false);
		owner.getCollider()->~ColliderComponent();
	}
}

void NPCDogDeathState::exit()
{
}
