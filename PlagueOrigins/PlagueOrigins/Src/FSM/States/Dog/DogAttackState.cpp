#include "stdafx.h"
#include "./DogStates.h"

DogAttackState::DogAttackState(Entity& owner) :
	owner(owner)
{
}

void DogAttackState::enter()
{
	std::cout << "ATTACK\n";
	Animator& animator = owner.GetComponent<Animator>();

	animator.previousAnimation = animator.currentAnimation;
	animator.currentAnimation = ATTACK;

	Attack& attack = owner.GetComponent<Attack>();
	attack.isAttacking = true;
}

void DogAttackState::update(const float& dt)
{
    if (owner.GetComponent<Health>().curhealth <= 0)
    {
        PlayerSMcomponent& playerStates = owner.GetComponent<PlayerSMcomponent>();
        playerStates.currentState = playerStates.changeState(playerStates.currentState,
            new DogDeathState(owner));
        std::cout << "";
    }
    else if (owner.GetComponent<Animator>().armatureDisplay->getAnimation()->isCompleted())
    {

        std::cout << "finish\n";
        if (owner.GetComponent<Attack>().isAttacking)
        {
            PlayerSMcomponent& playerStates = owner.GetComponent<PlayerSMcomponent>();
            playerStates.currentState = playerStates.changeState(playerStates.currentState,
                new DogAttackState(owner));
            std::cout << "";
        }
        else
        {
            PlayerSMcomponent& playerStates = owner.GetComponent<PlayerSMcomponent>();
            playerStates.currentState = playerStates.changeState(playerStates.currentState,
                new DogIdleState(owner));
            std::cout << "";
        }
    }
}

void DogAttackState::exit()
{
    Attack& attack = owner.GetComponent<Attack>();
    attack.isAttacking = false;
}
