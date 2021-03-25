#include "stdafx.h"

#include "AnimationComponent.h"

//Constructor/Destructor
AnimationComponent::AnimationComponent(sf::RectangleShape& shape, dragonBones::SFMLFactory* zf, std::string prefix) : shape(shape)
{
	//this->factory.clear();
	this->prefix = prefix;
	this->factory = zf;
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
		//this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroRunN");
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

void AnimationComponent::updateFactory(float dt)
{
	this->factory->update(dt);
	//this->zf->get()->update(dt);
}

void AnimationComponent::initArmature(sf::Vector2f vec)
{
	//LOAD
	//this->factory.clear();
	//this->texture1.loadFromFile("./Assets/AnimationSep2/heroAnim/heroAnimAttack_tex.png");
	//this->factory.loadDragonBonesData("./Assets/AnimationSep2/heroAnim/heroAnimAttack_ske.json");
	//this->factory.loadTextureAtlasData("./Assets/AnimationSep2/heroAnim/heroAnimAttack_tex.json", &texture1);
	//this->texture2.loadFromFile("./Assets/AnimationSep2/heroAnim/heroAnimRun_tex.png");
	//this->factory.loadDragonBonesData("./Assets/AnimationSep2/heroAnim/heroAnimRun_ske.json");
	//this->factory.loadTextureAtlasData("./Assets/AnimationSep2/heroAnim/heroAnimRun_tex.json", &texture2);
	//this->texture3.loadFromFile("./Assets/Animation/enemyAnim/enemyAnim_tex.png");
	//this->factory.loadDragonBonesData("./Assets/Animation/enemyAnim/enemyAnim_ske.json");
	//this->factory.loadTextureAtlasData("./Assets/Animation/enemyAnim/enemyAnim_tex.json", &texture3);

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
		return "Run";
	if (name == 3)
		return "Dash";
	if (name == 4)
		return "Attack";
}