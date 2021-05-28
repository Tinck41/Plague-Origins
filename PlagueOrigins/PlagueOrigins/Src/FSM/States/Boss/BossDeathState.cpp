#include "stdafx.h"
#include "BossStates.h"

BossDeathState::BossDeathState(Entity& owner) :
	owner(owner)
{
	delay = sf::seconds(2.f);
}

void BossDeathState::enter()
{
	std::cout << "Boss Death State\n";
	Animator& animator = owner.GetComponent<Animator>();

	animator.previousAnimation = animator.currentAnimation;
	animator.currentAnimation = DIE;

	owner.RemoveComponent<Movement>();

	//Timer
	last = gameClock.getElapsedTime();
}

void BossDeathState::update(const float& dt)
{
	now = gameClock.getElapsedTime();
	if (now - last >= delay)
	{
		//dispose
		std::cout << "dispose true\n";
		owner.GetComponent<Dispose>().toDispose = true;
	}
}

void BossDeathState::exit()
{
}
