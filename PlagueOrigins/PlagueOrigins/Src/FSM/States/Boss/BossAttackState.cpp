#include "stdafx.h"
#include "BossStates.h"

BossAttackState::BossAttackState(Entity& owner) :
    owner(owner)
{
}

void BossAttackState::enter()
{
    std::cout << "Boss Attack State\n";
    Animator& animator = owner.GetComponent<Animator>();

    animator.previousAnimation = animator.currentAnimation;
    animator.currentAnimation = ATTACK;

    owner.RemoveComponent<Movement>();

    Attack& attack = owner.GetComponent<Attack>();
    attack.isAttacking = true;
}

void BossAttackState::update(const float& dt)
{
    if (owner.GetComponent<Health>().curhealth <= 0)
    {
        SMcomponent& playerStates = owner.GetComponent<SMcomponent>();
        playerStates.currentState = playerStates.changeState(playerStates.currentState,
            new BossDeathState(owner));
        std::cout << "";
    }
    else if (owner.GetComponent<Animator>().armatureDisplay->getAnimation()->isCompleted())
    {
        std::cout << "finish\n";
        if (owner.GetComponent<Attack>().radius >= owner.GetComponent<Aggresion>().distanceToTarget)
        {
            Animator& animator = owner.GetComponent<Animator>();
            animator.armatureDisplay->getAnimation()->play(animator.armatureDisplay->getAnimation()->getLastAnimationName(), 1);
            animator.previousAnimation = animator.currentAnimation;
            animator.currentAnimation = ATTACK;

            Attack& attack = owner.GetComponent<Attack>();
            attack.isAttacking = true;
            std::cout << "";
        }
        else if (owner.GetComponent<Aggresion>().isAggresive)
        {
            SMcomponent& playerStates = owner.GetComponent<SMcomponent>();
            playerStates.currentState = playerStates.changeState(playerStates.currentState,
                new BossAggroState(owner));
            std::cout << "";
        }
        else
        {
            SMcomponent& playerStates = owner.GetComponent<SMcomponent>();
            playerStates.currentState = playerStates.changeState(playerStates.currentState,
                new BossIdleState(owner));
            std::cout << "";
        }
    }
}

void BossAttackState::exit()
{
    Attack& attack = owner.GetComponent<Attack>();
    attack.isAttacking = false;
    owner.AddComponent<Movement>(config.bossSpeed);
}
