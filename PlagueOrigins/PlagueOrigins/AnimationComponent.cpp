#include "stdafx.h"

#include "AnimationComponent.h"

//Constructor/Destructor
AnimationComponent::AnimationComponent(sf::RectangleShape& shape, dragonBones::SFMLFactory& zf, std::string prefix) : factory(zf), shape(shape)
{
	//this->factory.clear();
	this->prefix = prefix;
	//this->factory = zf;
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
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureHeroMoveU");
	}
	else if (this->currentDirection.y == 1.f)
	{
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureHeroMoveD");
	}
	if (this->currentDirection.x == 1.f)
	{
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureHeroMoveR");
	}
	else if (this->currentDirection.x == -1.f)
	{
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureHeroMoveR");
		this->armatureDisplay->getArmature()->setFlipX(true);
	}
	this->armatureDisplay->getAnimation()->play("Run");
}

void AnimationComponent::playIdleAnimation()
{
	if (this->currentDirection.y == -1.f)
	{
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureHeroMoveU");
	}
	else if (this->currentDirection.y == 1.f)
	{
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureHeroMoveD");
	}
	if (this->currentDirection.x == 1.f)
	{
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureHeroMoveR");
	}
	else if (this->currentDirection.x == -1.f)
	{	
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureHeroMoveR");
		this->armatureDisplay->getArmature()->setFlipX(true);
	}
	this->armatureDisplay->getAnimation()->play("Idle");
}

void AnimationComponent::playAttackAnimation()
{
	if (this->currentDirection.y == -1.f)
	{
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureHeroAttackU");
		//this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroRunN");
		this->armatureDisplay->getAnimation()->play("Attack", 1);
	}
	else if (this->currentDirection.y == 1.f)
	{
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureHeroAttackD");
		this->armatureDisplay->getAnimation()->play("Attack", 1);
	}

	if (this->currentDirection.x == 1.f)
	{
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureHeroAttackR");
		this->armatureDisplay->getAnimation()->play("Attack", 1);
	}
	else if (this->currentDirection.x == -1.f)
	{
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureHeroAttackR");
		this->armatureDisplay->getArmature()->setFlipX(true);
		this->armatureDisplay->getAnimation()->play("Attack", 1);
	}
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
			this->armatureDisplay = nullptr;
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
			this->armatureDisplay->getArmature()->dispose();
		}

		this->playAnimation();
	}
}

std::string AnimationComponent::enumToString(animationName name)
{
	if (name == 0)
		return "None";
	if (name == 1)
		return "Idle";
	if (name == 2)
		return "Move";
	if (name == 3)
		return "Dash";
	if (name == 4)
		return "Attack";
}