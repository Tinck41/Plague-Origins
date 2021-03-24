#include "stdafx.h"

#include "AnimationComponent.h"

//Constructor/Destructor
AnimationComponent::AnimationComponent(sf::RectangleShape& shape) : shape(shape)
{
	this->factory.clear();
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
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroRunN", "heroAnim", "heroAnim", "heroAnim");
		this->armatureDisplay->getAnimation()->play("RunN");
	}
	else if (this->currentDirection.y == 1.f)
	{
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroRunS", "heroAnim", "heroAnim", "heroAnim");
		this->armatureDisplay->getAnimation()->play("RunS");
	}

	if (this->currentDirection.x == 1.f)
	{
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroRunEW", "heroAnim", "heroAnim", "heroAnim");
		this->armatureDisplay->getAnimation()->play("RunEW");
	}
	else if (this->currentDirection.x == -1.f)
	{
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroRunEW", "heroAnim", "heroAnim", "heroAnim");
		this->armatureDisplay->getArmature()->setFlipX(true);
		this->armatureDisplay->getAnimation()->play("RunEW");
	}
}

void AnimationComponent::playIdleAnimation()
{
	if (this->currentDirection.y == -1.f)
	{
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroRunN", "heroAnim", "heroAnim", "heroAnim");
		this->armatureDisplay->getAnimation()->play("Idle");
	}
	else if (this->currentDirection.y == 1.f)
	{
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroIdle", "heroAnim", "heroAnim", "heroAnim");
		this->armatureDisplay->getAnimation()->play("Idle");
	}

	if (this->currentDirection.x == 1.f)
	{
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroRunEW", "heroAnim", "heroAnim", "heroAnim");
		this->armatureDisplay->getAnimation()->play("Idle");
	}
	else if (this->currentDirection.x == -1.f)
	{	
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroRunEW", "heroAnim", "heroAnim", "heroAnim");
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
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroRunN", "heroAnim", "heroAnim", "heroAnim");
		this->armatureDisplay->getAnimation()->play("Idle", 1);
	}
	else if (this->currentDirection.y == 1.f)
	{
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroAttackS", "heroAnim", "heroAnim", "heroAnim");
		this->armatureDisplay->getAnimation()->play("Attack", 1);
	}

	if (this->currentDirection.x == 1.f)
	{
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroAttackE", "heroAnim", "heroAnim", "heroAnim");
		this->armatureDisplay->getAnimation()->play("Attack", 1);
	}
	else if (this->currentDirection.x == -1.f)
	{
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroAttackE", "heroAnim", "heroAnim", "heroAnim");
		this->armatureDisplay->getArmature()->setFlipX(true);
		this->armatureDisplay->getAnimation()->play("Attack", 1);
	}
}

void AnimationComponent::updateFactory(float dt)
{
	//this->factory.update(dt);
	this->zf->get()->update(dt);
}

void AnimationComponent::initArmature(sf::Vector2f vec)
{
	//LOAD
	//this->factory.clear();
	//this->texture.loadFromFile("./Assets/AnimationSep/heroAnim/heroAnimAttack_tex.png");
	//this->factory.loadDragonBonesData("./Assets/AnimationSep/heroAnim/heroAnimAttack_ske.json");
	//this->factory.loadTextureAtlasData("./Assets/AnimationSep/heroAnim/heroAnimAttack_tex.json", &texture);
	//this->texture.loadFromFile("./Assets/AnimationSep/heroAnim/heroAnimRun_tex.png");
	//this->factory.loadDragonBonesData("./Assets/AnimationSep/heroAnim/heroAnimRun_ske.json");
	//this->factory.loadTextureAtlasData("./Assets/AnimationSep/heroAnim/heroAnimRun_tex.json", &texture);
	//this->texture.loadFromFile("./Assets/AnimationSep/heroAnim/heroAnimAttack_tex.png");
	//this->zf->get()->loadDragonBonesData("./Assets/AnimationSep/heroAnim/heroAnimAttack_ske.json");
	//this->zf->get()->loadTextureAtlasData("./Assets/AnimationSep/heroAnim/heroAnimAttack_tex.json", &texture);
	//this->texture.loadFromFile("./Assets/AnimationSep/heroAnim/heroAnimRun_tex.png");
	//this->zf->get()->loadDragonBonesData("./Assets/AnimationSep/heroAnim/heroAnimRun_ske.json");
	//this->zf->get()->loadTextureAtlasData("./Assets/AnimationSep/heroAnim/heroAnimRun_tex.json", &texture);

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