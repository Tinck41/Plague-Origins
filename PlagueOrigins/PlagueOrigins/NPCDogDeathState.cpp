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
	if (owner.getActiveStatus())
	{
		std::cout << "Dog death state\n";
		owner.getAnimator()->setAnimation(animationName::DIE);

		//Timer
		last = gameClock.getElapsedTime();
	}
}

void NPCDogDeathState::update(const float& dt)
{
	if (owner.getActiveStatus())
	{
		now = gameClock.getElapsedTime();
		if (now - last >= delay)
		{
			owner.setActiveStatus(false);
			exit();
		}
	}
}

void NPCDogDeathState::exit()
{
	std::cout << "Dog EXIT death state\n";
	owner.getCollider()->destroyBody();
	owner.~NPCDog();
	//owner.getCollider()->~ColliderComponent();
	//owner.getCombatComponent()->~CombatComponent();
}
