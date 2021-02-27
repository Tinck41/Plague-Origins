#include "AnimationComponent.h"

//Constructor/Destructor
AnimationComponent::AnimationComponent(sf::RectangleShape& shape, dragonBones::SFMLFactory& factory) :
	factory(factory), shape(shape)
{
}

AnimationComponent::~AnimationComponent()
{
}

void AnimationComponent::initArmature(sf::Vector2f vec)
{
	//IDLE:

	this->texture.loadFromFile("./Assets/Animations/Hero/heroAnim/heroAnim_tex.png");

	this->factory.clear();
	this->factory.loadDragonBonesData("./Assets/Animations/Hero/heroAnim/heroAnim_ske.json");
	this->factory.loadTextureAtlasData("./Assets/Animations/Hero/heroAnim/heroAnim_tex.json", &texture);

	this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroIdle");
	
	this->armatureDisplay->setPosition(vec);

}

dragonBones::SFMLArmatureDisplay* AnimationComponent::playAnimation(int key, float posX, float posY)
{
	this->armatureDisplay->getArmature()->dispose();
	switch (key)
	{
	case IDLE:
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroIdle");
		this->armatureDisplay->getAnimation()->play("Idle");
		break;
	case RUN_UP:
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroRunN");
		this->armatureDisplay->getAnimation()->play("RunN");
		break;
	case RUN_RIGHT:
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroRunEW");
		this->armatureDisplay->getAnimation()->play("RunEW");
		break;
	case RUN_DOWN:
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroRunS");
		this->armatureDisplay->getAnimation()->play("RunS");
		break;
	case RUN_LEFT:
		this->armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroRunEW");
		this->armatureDisplay->getArmature()->setFlipX(true);
		this->armatureDisplay->getAnimation()->play("RunEW");
		break;
	case ROLL:
		/*
			WIP
		*/
		break;
	}
	return armatureDisplay;
}