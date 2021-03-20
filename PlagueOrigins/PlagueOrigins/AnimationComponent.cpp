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

void AnimationComponent::setMovementAnimation(unsigned state)
{
	this->curState = state;

	switch (state)
	{
	case 4:
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroRunN");
		this->armatureDisplay->getAnimation()->play("RunN");
		break;
	case 3:
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroRunEW");
		this->armatureDisplay->getAnimation()->play("RunEW");
		break;
	case 1:
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroRunS");
		this->armatureDisplay->getAnimation()->play("RunS");
		break;
	case 2:
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroRunEW");
		this->armatureDisplay->getArmature()->setFlipX(true);
		this->armatureDisplay->getAnimation()->play("RunEW");
		break;
	}
}

void AnimationComponent::setIdleAnimation(unsigned state)
{
	this->curState = state;

	switch (state)
	{
	case 0:
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroIdle");
		this->armatureDisplay->getAnimation()->play("Idle");
		break;
	case 3:
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroIdle");
		this->armatureDisplay->getAnimation()->play("Idle");
		break;
	case 1:
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroIdle");
		this->armatureDisplay->getAnimation()->play("Idle");
		break;
	case 2:
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroIdle");
		this->armatureDisplay->getAnimation()->play("Idle");
		break;
	}
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

dragonBones::SFMLArmatureDisplay* AnimationComponent::playAnimation(unsigned globalState, unsigned localState)
{
	if (this->curState != localState)
	{
		if (this->armatureDisplay->getArmature() != NULL)
			this->armatureDisplay->getArmature()->dispose();

		switch (globalState)
		{
		case 0:
			this->setIdleAnimation(localState);
			break;
		case 1:
			this->setMovementAnimation(localState);
			break;
		case 2:
			break;
		case 3:
			break;
		}
	}
	return this->armatureDisplay;
}