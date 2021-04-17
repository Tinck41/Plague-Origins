#include "stdafx.h"

#include "AnimationComponent.h"

//Constructor/Destructor
AnimationComponent::AnimationComponent(sf::RectangleShape& shape, dragonBones::SFMLFactory& zf, std::string prefix) : 
	factory(zf), shape(shape)
{
	this->prefix = prefix;
	this->armatureName = "Armature" + prefix;
}

AnimationComponent::~AnimationComponent()
{

}

void AnimationComponent::playAnimation()
{
	switch (this->currentAnimation)
	{
	case(animationName::IDLE):
		this->playIdleAnimation();
		break;
	case(animationName::MOVE):
		this->playMovementAnimation();
		break;
	case(animationName::ATTACK):
		this->playAttackAnimation();
		break;
	case(animationName::DIE):
		this->playDeathAnimation();
		break;
	default:
		break;
	}
}

void AnimationComponent::playMovementAnimation()
{
	if (this->currentDirection.y == -1.f)
	{
		this->postfix = this->setPostfix("U");
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay(this->armatureName + this->postfix);
	}
	else if (this->currentDirection.y == 1.f)
	{
		this->postfix = this->setPostfix("D");
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay(this->armatureName + this->postfix);
	}
	if (this->currentDirection.x == 1.f)
	{
		this->postfix = this->setPostfix("R");
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay(this->armatureName + this->postfix);
	}
	else if (this->currentDirection.x == -1.f)
	{
		this->postfix = this->setPostfix("R");
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay(this->armatureName + this->postfix);
		this->armatureDisplay->getArmature()->setFlipX(true);
	}
	//this->armatureDisplay->getAnimation()->play("Run");
	this->armatureDisplay->getAnimation()->fadeIn("Run", 0.3f, -1, 0, "hero", dragonBones::AnimationFadeOutMode::SameLayerAndGroup);
}

void AnimationComponent::playIdleAnimation()
{
	if (this->currentDirection.y == -1.f)
	{
		this->postfix = this->setPostfix("U");
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay(this->armatureName + this->postfix);
	}
	else if (this->currentDirection.y == 1.f)
	{
		this->postfix = this->setPostfix("D");
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay(this->armatureName + this->postfix);
	}
	if (this->currentDirection.x == 1.f)
	{
		this->postfix = this->setPostfix("R");
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay(this->armatureName + this->postfix);
	}
	else if (this->currentDirection.x == -1.f)
	{	
		this->postfix = this->setPostfix("R");
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay(this->armatureName + this->postfix);
		this->armatureDisplay->getArmature()->setFlipX(true);
	}
	//this->armatureDisplay->getAnimation()->play("Idle");
	this->armatureDisplay->getAnimation()->fadeIn("Idle", .5f, -1, 0, "hero", dragonBones::AnimationFadeOutMode::SameLayerAndGroup);
}

void AnimationComponent::playAttackAnimation()
{
	if (this->currentDirection.y == -1.f)
	{
		this->postfix = this->setPostfix("U");
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay(this->armatureName + this->postfix);
	}
	else if (this->currentDirection.y == 1.f)
	{
		this->postfix = this->setPostfix("D");
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay(this->armatureName + this->postfix);
	}
	if (this->currentDirection.x == 1.f)
	{
		this->postfix = this->setPostfix("R");
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay(this->armatureName + this->postfix);
	}
	else if (this->currentDirection.x == -1.f)
	{
		this->postfix = this->setPostfix("R");
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay(this->armatureName + this->postfix);
		this->armatureDisplay->getArmature()->setFlipX(true);
	}
	if (prefix == "Hero")
	{
		//this->armatureDisplay->getAnimation()->fadeIn("Attack", 0.2f, 1);
		this->armatureDisplay->getAnimation()->play("Attack", 1);

	}
	else if (prefix == "Dog")
	{
		this->armatureDisplay->getAnimation()->play("Attack0", 1);
	}
}

void AnimationComponent::playDeathAnimation()
{
	if (this->currentDirection.y == -1.f)
	{
		this->postfix = this->setPostfix("U");
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay(this->armatureName + this->postfix);
	}
	else if (this->currentDirection.y == 1.f)
	{
		this->postfix = this->setPostfix("D");
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay(this->armatureName + this->postfix);
	}
	if (this->currentDirection.x == 1.f)
	{
		this->postfix = this->setPostfix("R");
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay(this->armatureName + this->postfix);
	}
	else if (this->currentDirection.x == -1.f)
	{
		this->postfix = this->setPostfix("R");
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay(this->armatureName + this->postfix);
		this->armatureDisplay->getArmature()->setFlipX(true);
	}
	this->armatureDisplay->getAnimation()->play("Die", 1);
	//this->armatureDisplay->getAnimation()->fadeIn("Die", 1.f, 1);
}

void AnimationComponent::updateFactory(float dt)
{
	this->factory.update(dt);
}

void AnimationComponent::initArmature(sf::Vector2f vec)
{
	//IDLE:
	armatureDisplay = nullptr;
	//this->armatureDisplay->setPosition(vec);
}

void AnimationComponent::setAnimation(animationName newAnimation, sf::Vector2f newDirection)
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
			this->currentDirection = newDirection;
			this->currentAnimation = newAnimation;

			if (this->armatureDisplay != nullptr)
			{
				this->armatureDisplay->getArmature()->~Armature();
				delete armatureDisplay;
				//armatureDisplay = NULL;
			}

			this->playAnimation();
		}
	}
}

void AnimationComponent::setAnimation(animationName newAnimation)
{
	if (newAnimation != currentAnimation) 
	{
		this->currentAnimation = newAnimation;

		if (this->armatureDisplay != nullptr)
		{
			this->armatureDisplay->getArmature()->~Armature();
			delete armatureDisplay;
			//armatureDisplay = NULL;
		}

		this->playAnimation();
	}
}

std::string AnimationComponent::setPostfix(std::string dir)
{
	if (prefix != "Bishop")
	{
		if (dir == "U")
			return dir;
		if (dir == "R")
			return dir;
		if (dir == "D")
			return dir;
	}
	else
		return "";
}