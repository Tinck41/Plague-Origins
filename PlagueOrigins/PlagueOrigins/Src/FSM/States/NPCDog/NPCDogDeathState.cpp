#include "stdafx.h"
#include "./NPCDogStates.h"

NPCDogDeathState::NPCDogDeathState(Entity& owner) :
	owner(owner)
{
	delay = sf::seconds(2.f);
}

void NPCDogDeathState::enter()
{
	std::cout << "DIE\n";
	Animator& animator = owner.GetComponent<Animator>();

	animator.previousAnimation = animator.currentAnimation;
	animator.currentAnimation = DIE;

	//Timer
	last = gameClock.getElapsedTime();
}

void NPCDogDeathState::update(const float& dt)
{
	now = gameClock.getElapsedTime();
	if (now - last >= delay)
	{
		//dispose
	}
}

void NPCDogDeathState::exit()
{
}
