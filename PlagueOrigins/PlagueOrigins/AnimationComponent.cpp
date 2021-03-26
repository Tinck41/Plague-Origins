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
	default:
		break;
	}
}

void AnimationComponent::playMovementAnimation()
{
	if (this->currentDirection.y == -1.f)
	{
		this->postfix = this->setPostfix(this->prefix, "U");
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay(this->armatureName + this->postfix);
	}
	else if (this->currentDirection.y == 1.f)
	{
		this->postfix = this->setPostfix(this->prefix, "D");
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay(this->armatureName + this->postfix);
	}
	if (this->currentDirection.x == 1.f)
	{
		this->postfix = this->setPostfix(this->prefix, "R");
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay(this->armatureName + this->postfix);
	}
	else if (this->currentDirection.x == -1.f)
	{
		this->postfix = this->setPostfix(this->prefix, "R");
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay(this->armatureName + this->postfix);
		this->armatureDisplay->getArmature()->setFlipX(true);
	}
	this->armatureDisplay->getAnimation()->play("Run");
}

void AnimationComponent::playIdleAnimation()
{
	if (this->currentDirection.y == -1.f)
	{
		this->postfix = this->setPostfix(this->prefix, "U");
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay(this->armatureName + this->postfix);
	}
	else if (this->currentDirection.y == 1.f)
	{
		this->postfix = this->setPostfix(this->prefix, "D");
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay(this->armatureName + this->postfix);
	}
	if (this->currentDirection.x == 1.f)
	{
		this->postfix = this->setPostfix(this->prefix, "R");
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay(this->armatureName + this->postfix);
	}
	else if (this->currentDirection.x == -1.f)
	{	
		this->postfix = this->setPostfix(this->prefix, "R");
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay(this->armatureName + this->postfix);
		this->armatureDisplay->getArmature()->setFlipX(true);
	}
	this->armatureDisplay->getAnimation()->play("Idle");
}

void AnimationComponent::playAttackAnimation()
{
	
	if (this->currentDirection.y == -1.f)
	{
		this->postfix = this->setPostfix(this->prefix, "U");
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay(this->armatureName + this->postfix);
	}
	else if (this->currentDirection.y == 1.f)
	{
		this->postfix = this->setPostfix(this->prefix, "D");
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay(this->armatureName + this->postfix);
	}
	if (this->currentDirection.x == 1.f)
	{
		this->postfix = this->setPostfix(this->prefix, "R");
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay(this->armatureName + this->postfix);
	}
	else if (this->currentDirection.x == -1.f)
	{
		this->postfix = this->setPostfix(this->prefix, "R");
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay(this->armatureName + this->postfix);
		this->armatureDisplay->getArmature()->setFlipX(true);
	}
	this->armatureDisplay->getAnimation()->play("Attack", 1);
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
		this->currentDirection = newDirection;
		this->currentAnimation = newAnimation;

		if (this->armatureDisplay != nullptr)
		{
			this->armatureDisplay->getArmature()->~Armature();
			delete armatureDisplay;
		}

		this->playAnimation();
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
		}

		this->playAnimation();
	}
}

std::string AnimationComponent::setPostfix(std::string prefix, std::string dir)
{
	if (prefix == "Dog")
	{
		if (dir == "U")
			return "D";
		if (dir == "R")
			return dir;
		if (dir == "D")
			return dir;
	}
	if (prefix == "Hero")
	{
		if (this->currentAnimation == animationName::IDLE || this->currentAnimation == animationName::MOVE)
			return "Move" + dir;
		if (this->currentAnimation == animationName::ATTACK)
			return "Attack" + dir;
	}
}