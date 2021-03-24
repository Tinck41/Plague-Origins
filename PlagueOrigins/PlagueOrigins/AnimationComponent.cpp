#include "stdafx.h"

#include "AnimationComponent.h"

//Constructor/Destructor
AnimationComponent::AnimationComponent(sf::RectangleShape& shape, dragonBones::SFMLFactory& factory) :
	factory(factory), shape(shape)
{
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
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroRunN");
		this->armatureDisplay->getAnimation()->play("RunN");
	}
	else if (this->currentDirection.y == 1.f)
	{
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroRunS");
		this->armatureDisplay->getAnimation()->play("RunS");
	}

	if (this->currentDirection.x == 1.f)
	{
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroRunEW");
		this->armatureDisplay->getAnimation()->play("RunEW");
	}
	else if (this->currentDirection.x == -1.f)
	{
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroRunEW");
		this->armatureDisplay->getArmature()->setFlipX(true);
		this->armatureDisplay->getAnimation()->play("RunEW");
	}
}

void AnimationComponent::playIdleAnimation()
{
	if (this->currentDirection.y == -1.f)
	{
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroRunN");
		this->armatureDisplay->getAnimation()->play("Idle");
	}
	else if (this->currentDirection.y == 1.f)
	{
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroIdle");
		this->armatureDisplay->getAnimation()->play("Idle");
	}

	if (this->currentDirection.x == 1.f)
	{
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroRunEW");
		this->armatureDisplay->getAnimation()->play("Idle");
	}
	else if (this->currentDirection.x == -1.f)
	{	
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroRunEW");
		this->armatureDisplay->getArmature()->setFlipX(true);
		this->armatureDisplay->getAnimation()->play("Idle");
	}
	//this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroIdle");
	//this->armatureDisplay->getAnimation()->play("Idle");
}

void AnimationComponent::playAttackAnimation()
{
	if (this->currentDirection.y == -1.f)
	{
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroRunN");
		this->armatureDisplay->getAnimation()->play("Idle", 1);
	}
	else if (this->currentDirection.y == 1.f)
	{
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroAttackS");
		this->armatureDisplay->getAnimation()->play("Attack", 1);
	}

	if (this->currentDirection.x == 1.f)
	{
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroAttackE");
		this->armatureDisplay->getAnimation()->play("Attack", 1);
	}
	else if (this->currentDirection.x == -1.f)
	{
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroAttackE");
		this->armatureDisplay->getArmature()->setFlipX(true);
		this->armatureDisplay->getAnimation()->play("Attack", 1);
	}
}

void AnimationComponent::initArmature(sf::Vector2f vec)
{
	//LOAD
	this->texture.loadFromFile("./Assets/AnimationNew/heroAnim/heroAnim_tex.png");

	this->factory.clear();
	this->factory.loadDragonBonesData("./Assets/AnimationNew/heroAnim/heroAnim_ske.json");
	this->factory.loadTextureAtlasData("./Assets/AnimationNew/heroAnim/heroAnim_tex.json", &texture);

	//IDLE:
	////this->armatureDisplay = std::make_unique <dragonBones::SFMLArmatureDisplay>("ArmatureheroIdle");
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
			this->armatureDisplay->getArmature()->dispose();
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