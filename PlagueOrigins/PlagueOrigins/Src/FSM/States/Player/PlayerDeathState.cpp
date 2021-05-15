#include "stdafx.h"
#include "./PlayerStates.h"

PlayerDeathState::PlayerDeathState(Entity& owner) :
	owner(owner)
{
}

void PlayerDeathState::enter()
{
    std::cout << "DIE\n";
    Animator& animator = owner.GetComponent<Animator>();
    Movement& movement = owner.GetComponent<Movement>();

    owner.RemoveComponent<Movement>();
    owner.RemoveComponent<Attack>();

    animator.previousAnimation = animator.currentAnimation;
    animator.currentAnimation = DIE;
}

void PlayerDeathState::update(const float& dt)
{
}

void PlayerDeathState::exit()
{
}
