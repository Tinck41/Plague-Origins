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
        SMcomponent& stateMachine = owner.GetComponent<SMcomponent>();
        stateMachine.currentState = stateMachine.changeState(stateMachine.currentState,
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
            SMcomponent& stateMachine = owner.GetComponent<SMcomponent>();
            stateMachine.currentState = stateMachine.changeState(stateMachine.currentState,
                new BossAggroState(owner));
            std::cout << "";
        }
        else
        {
            SMcomponent& stateMachine = owner.GetComponent<SMcomponent>();
            stateMachine.currentState = stateMachine.changeState(stateMachine.currentState,
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
