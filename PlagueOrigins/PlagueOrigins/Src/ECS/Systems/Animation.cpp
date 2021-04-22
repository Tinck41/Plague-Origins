#include "stdafx.h"
#include "Animation.h"

#include "Src/ECS/Components/Animator.h"
#include "Src/ECS/Components/Movement.h"
#include "Src/ECS/Components/PlayerInput.h"

void Animation::playAnimation(Animator& animator)
{
	switch ()
	{
	case(animationName::IDLE):
		playIdleAnimation();
		break;
	case(animationName::MOVE):
		playMovementAnimation(Animator& animator);
		break;
	case(animationName::ATTACK):
		playAttackAnimation();
		break;
	case(animationName::DIE):
		playDeathAnimation();
		break;
	default:
		break;
	}
}

void Animation::playMovementAnimation(Animator& animator)
{
	if (animator.currentDirection.y == -1.f)
	{
		animator.postfix = setPostfix("U");
		animator.armatureDisplay = new dragonBones::SFMLArmatureDisplay(armatureName + postfix);
	}
	else if (currentDirection.y == 1.f)
	{
		postfix = setPostfix("D");
		armatureDisplay = new dragonBones::SFMLArmatureDisplay(armatureName + postfix);
	}
	if (currentDirection.x == 1.f)
	{
		postfix = setPostfix("R");
		armatureDisplay = new dragonBones::SFMLArmatureDisplay(armatureName + postfix);
	}
	else if (currentDirection.x == -1.f)
	{
		postfix = setPostfix("R");
		armatureDisplay = new dragonBones::SFMLArmatureDisplay(armatureName + postfix);
		armatureDisplay->getArmature()->setFlipX(true);
	}
	//armatureDisplay->getAnimation()->play("Run");
	armatureDisplay->getAnimation()->fadeIn("Run", 0.3f, -1, 0, "hero", dragonBones::AnimationFadeOutMode::SameLayerAndGroup);
}

void Animation::playIdleAnimation()
{
	if (currentDirection.y == -1.f)
	{
		postfix = setPostfix("U");
		armatureDisplay = new dragonBones::SFMLArmatureDisplay(armatureName + postfix);
	}
	else if (currentDirection.y == 1.f)
	{
		postfix = setPostfix("D");
		armatureDisplay = new dragonBones::SFMLArmatureDisplay(armatureName + postfix);
	}
	if (currentDirection.x == 1.f)
	{
		postfix = setPostfix("R");
		armatureDisplay = new dragonBones::SFMLArmatureDisplay(armatureName + postfix);
	}
	else if (currentDirection.x == -1.f)
	{	
		postfix = setPostfix("R");
		armatureDisplay = new dragonBones::SFMLArmatureDisplay(armatureName + postfix);
		armatureDisplay->getArmature()->setFlipX(true);
	}
	//armatureDisplay->getAnimation()->play("Idle");
	armatureDisplay->getAnimation()->fadeIn("Idle", .5f, -1, 0, "hero", dragonBones::AnimationFadeOutMode::SameLayerAndGroup);
}

void Animation::playAttackAnimation()
{
	if (currentDirection.y == -1.f)
	{
		postfix = setPostfix("U");
		armatureDisplay = new dragonBones::SFMLArmatureDisplay(armatureName + postfix);
	}
	else if (currentDirection.y == 1.f)
	{
		postfix = setPostfix("D");
		armatureDisplay = new dragonBones::SFMLArmatureDisplay(armatureName + postfix);
	}
	if (currentDirection.x == 1.f)
	{
		postfix = setPostfix("R");
		armatureDisplay = new dragonBones::SFMLArmatureDisplay(armatureName + postfix);
	}
	else if (currentDirection.x == -1.f)
	{
		postfix = setPostfix("R");
		armatureDisplay = new dragonBones::SFMLArmatureDisplay(armatureName + postfix);
		armatureDisplay->getArmature()->setFlipX(true);
	}
	if (prefix == "Hero")
	{
		//armatureDisplay->getAnimation()->fadeIn("Attack", 0.2f, 1);
		armatureDisplay->getAnimation()->play("Attack", 1);

	}
	else if (prefix == "Dog")
	{
		armatureDisplay->getAnimation()->play("Attack0", 1);
	}
}

void Animation::playDeathAnimation()
{
	if (currentDirection.y == -1.f)
	{
		postfix = setPostfix("U");
		armatureDisplay = new dragonBones::SFMLArmatureDisplay(armatureName + postfix);
	}
	else if (currentDirection.y == 1.f)
	{
		postfix = setPostfix("D");
		armatureDisplay = new dragonBones::SFMLArmatureDisplay(armatureName + postfix);
	}
	if (currentDirection.x == 1.f)
	{
		postfix = setPostfix("R");
		armatureDisplay = new dragonBones::SFMLArmatureDisplay(armatureName + postfix);
	}
	else if (currentDirection.x == -1.f)
	{
		postfix = setPostfix("R");
		armatureDisplay = new dragonBones::SFMLArmatureDisplay(armatureName + postfix);
		armatureDisplay->getArmature()->setFlipX(true);
	}
	armatureDisplay->getAnimation()->play("Die", 1);
	//armatureDisplay->getAnimation()->fadeIn("Die", 1.f, 1);
}

std::string Animation::setPostfix(std::string dir)
{
	return std::string();
}

void Animation::initArmature(sf::Vector2f vec)
{
	//IDLE:
	armatureDisplay = nullptr;
}

void Animation::setAnimation(animationName newAnimation, sf::Vector2f newDirection)
{
	if (currentDirection != newDirection || currentAnimation != newAnimation)
	{
		/*
			if 
				start run in opposite direction by x 
			or 
				start run upwards-downwards
			change animation
			else 
				don't
		*/
		if (currentDirection.x != newDirection.x || currentDirection.x == 0 && newDirection.x == 0 || currentAnimation != newAnimation)
		{
			currentDirection = newDirection;
			currentAnimation = newAnimation;

			if (armatureDisplay != nullptr)
			{
				armatureDisplay->getArmature()->~Armature();
				delete armatureDisplay;
				armatureDisplay = NULL;
			}

			playAnimation();
		}
	}
}

void Animation::setAnimation(animationName newAnimation)
{
	if (newAnimation != currentAnimation) 
	{
		this->currentAnimation = newAnimation;

		if (this->armatureDisplay != nullptr)
		{
			this->armatureDisplay->getArmature()->~Armature();
			delete armatureDisplay;
			armatureDisplay = NULL;
		}

		this->playAnimation();
	}
}

void Animation::update(entt::registry& reg, const float& dt)
{
	auto view = reg.view<Animator, Movement>();
	for (auto entity : view)
	{
		Animator& animator = reg.get<Animator>(entity);
		Movement& movement = reg.get<Movement>(entity);
	}
}
