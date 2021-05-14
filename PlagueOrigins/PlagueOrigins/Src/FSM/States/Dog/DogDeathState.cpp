#include "stdafx.h"
#include "./DogStates.h"

DogDeathState::DogDeathState(Entity& owner) :
	owner(owner)
{
	delay = sf::seconds(2.f);
}

void DogDeathState::enter()
{
	std::cout << "DIE\n";
	Animator& animator = owner.GetComponent<Animator>();

	animator.previousAnimation = animator.currentAnimation;
	animator.currentAnimation = DIE;

	//Timer
	last = gameClock.getElapsedTime();
}

void DogDeathState::update(const float& dt)
{
	now = gameClock.getElapsedTime();
	if (now - last >= delay)
	{
		//dispose
	}
}

void DogDeathState::exit()
{
}
