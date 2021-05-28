#include "stdafx.h"
#include "./DogStates.h"

DogDeathState::DogDeathState(Entity& owner) :
	owner(owner)
{
	delay = sf::seconds(2.f);
}

void DogDeathState::enter()
{
	//std::cout << "Dog Death State\n";
	Animator& animator = owner.GetComponent<Animator>();

	animator.previousAnimation = animator.currentAnimation;
	animator.currentAnimation = DIE;

	owner.RemoveComponent<Movement>();

	//Timer
	last = gameClock.getElapsedTime();
}

void DogDeathState::update(const float& dt)
{
	now = gameClock.getElapsedTime();
	if (now - last >= delay)
	{
		//dispose
		owner.GetComponent<Dispose>().toDispose = true;
	}
}

void DogDeathState::exit()
{
}
