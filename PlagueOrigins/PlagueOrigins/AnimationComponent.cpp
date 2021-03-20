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
	case(animationName::IDLE) :
		this->playIdleAnimation();
		break;
	case(animationName::MOVE):
		this->playMovementAnimation();
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
	this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroIdle");
	this->armatureDisplay->getAnimation()->play("Idle");

	//this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroIdle");
	//this->armatureDisplay->getAnimation()->play("Idle");

	//this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroIdle");
	//this->armatureDisplay->getAnimation()->play("Idle");

	//this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroIdle");
	//this->armatureDisplay->getAnimation()->play("Idle");

}

void AnimationComponent::initArmature(sf::Vector2f vec)
{
	//LOAD
	this->texture.loadFromFile("./Assets/Animations/Hero/heroAnim/heroAnim_tex.png");

	this->factory.clear();
	this->factory.loadDragonBonesData("./Assets/Animations/Hero/heroAnim/heroAnim_ske.json");
	this->factory.loadTextureAtlasData("./Assets/Animations/Hero/heroAnim/heroAnim_tex.json", &texture);

	//IDLE:
	this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroIdle");
	
	this->armatureDisplay->setPosition(vec);
}

void AnimationComponent::setAnimation(animationName newAnimation, sf::Vector2f newDirection)
{
	if (this->currentDirection != newDirection)
	{
		this->currentDirection = newDirection;
		this->currentAnimation = newAnimation;

		if (this->armatureDisplay->getArmature() != NULL)
			this->armatureDisplay->getArmature()->dispose();

		this->playAnimation();
	}
}

void AnimationComponent::setAnimation(animationName newAnimation)
{
		this->currentAnimation = newAnimation;

		if (this->armatureDisplay->getArmature() != NULL)
			this->armatureDisplay->getArmature()->dispose();

		this->playAnimation();
}