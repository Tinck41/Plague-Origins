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
    ActorAudioSource& audioSource = owner.GetComponent<ActorAudioSource>();

    audioSource.playAttackSound = true;

    animator.previousAnimation = animator.currentAnimation;
    animator.currentAnimation = ATTACK;

    owner.RemoveComponent<Movement>();

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
        if (owner.GetComponent<Dash>().isDashing)
        {
            PlayerSMcomponent& playerStates = owner.GetComponent<PlayerSMcomponent>();
            playerStates.currentState = playerStates.changeState(playerStates.currentState,
                new PlayerDashState(owner));
            std::cout << "";
        }
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
    owner.AddComponent<Movement>(config.playerSpeed);
}
