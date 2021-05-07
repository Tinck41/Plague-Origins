#include "stdafx.h"
#include "NPCDogAttackState.h"

NPCDogAttackState::NPCDogAttackState(Entity& owner) :
	owner(owner)
{
}

void NPCDogAttackState::enter()
{
	std::cout << "ATTACK\n";
	Animator& animator = owner.GetComponent<Animator>();

	animator.previousAnimation = animator.currentAnimation;
	animator.currentAnimation = ATTACK;

	Attack& attack = owner.GetComponent<Attack>();
	attack.isAttacking = true;
}

void NPCDogAttackState::update(const float& dt)
{
    if (owner.GetComponent<Health>().curhealth <= 0)
    {
        PlayerSMcomponent& playerStates = owner.GetComponent<PlayerSMcomponent>();
        playerStates.currentState = playerStates.changeState(playerStates.currentState,
            new NPCDogDeathState(owner));
        std::cout << "";
    }
    else if (owner.GetComponent<Animator>().armatureDisplay->getAnimation()->isCompleted())
    {

        std::cout << "finish\n";
        if (owner.GetComponent<Attack>().isAttacking)
        {
            PlayerSMcomponent& playerStates = owner.GetComponent<PlayerSMcomponent>();
            playerStates.currentState = playerStates.changeState(playerStates.currentState,
                new NPCDogAttackState(owner));
            std::cout << "";
        }
        else
        {
            PlayerSMcomponent& playerStates = owner.GetComponent<PlayerSMcomponent>();
            playerStates.currentState = playerStates.changeState(playerStates.currentState,
                new NPCDogIdleState(owner));
            std::cout << "";
        }
    }
}

void NPCDogAttackState::exit()
{
    Attack& attack = owner.GetComponent<Attack>();
    attack.isAttacking = false;
}
