#include "stdafx.h"
#include "./BishopStates.h"

BishopDeathState::BishopDeathState(Entity& owner) :
	owner(owner)
{
	delay = sf::seconds(2.f);
}

void BishopDeathState::enter()
{
	std::cout << "DIE\n";
	Animator& animator = owner.GetComponent<Animator>();

	animator.previousAnimation = animator.currentAnimation;
	animator.currentAnimation = DIE;

	//Timer
	last = gameClock.getElapsedTime();
}

void BishopDeathState::update(const float& dt)
{
	now = gameClock.getElapsedTime();
	if (now - last >= delay)
	{
		//dispose
	}
}

void BishopDeathState::exit()
{
}
