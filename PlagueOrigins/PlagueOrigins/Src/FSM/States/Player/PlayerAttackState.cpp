#include "stdafx.h"
#include "./PlayerStates.h"

PlayerAttackState::PlayerAttackState(Entity& owner) :
    owner(owner)
{
}


void PlayerAttackState::enter()
{
    std::cout << "ATTACK\n";
    Animator& animator = owner.GetComponent<Animator>();

    animator.previousAnimation = animator.currentAnimation;
    animator.currentAnimation = ATTACK;

    Attack& attack = owner.GetComponent<Attack>();
    attack.isAttacking = true;
}

void PlayerAttackState::update(const float& dt)
{
 	if (owner.GetComponent<Health>().curhealth <= 0)
 	{
        PlayerSMcomponent& playerStates = owner.GetComponent<PlayerSMcomponent>();
        playerStates.currentState = playerStates.changeState(playerStates.currentState, 
            new PlayerDeathState(owner));
        std::cout << "";
 	}
 	else if (owner.GetComponent<Animator>().armatureDisplay->getAnimation()->isCompleted())
 	{
        
        std::cout << "finish\n";
 		if (owner.GetComponent<Attack>().isAttacking)
 		{
            PlayerSMcomponent& playerStates = owner.GetComponent<PlayerSMcomponent>();
            playerStates.currentState = playerStates.changeState(playerStates.currentState, 
                new PlayerAttackState(owner));
            std::cout << "";
 		}
 		else
 		{
            PlayerSMcomponent& playerStates = owner.GetComponent<PlayerSMcomponent>();
            playerStates.currentState = playerStates.changeState(playerStates.currentState,
                new PlayerIdleState(owner));
            std::cout << "";
 		}
 	}
}

void PlayerAttackState::exit()
{
    Attack& attack = owner.GetComponent<Attack>();
    attack.isAttacking = false;
}
