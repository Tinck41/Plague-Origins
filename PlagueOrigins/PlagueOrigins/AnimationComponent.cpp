#include "AnimationComponent.h"

//Constructor/Destructor
AnimationComponent::AnimationComponent(sf::RectangleShape shape, dragonBones::SFMLFactory& factory) :
	factory(factory)
{
	this->shape = shape;
}

AnimationComponent::~AnimationComponent()
{
}


const bool& AnimationComponent::isDone() const
{
	return true;
	// TODO: insert return statement here
}

dragonBones::SFMLArmatureDisplay* AnimationComponent::initAnimation(int key, float posX, float posY)
{
	//IDLE:
	this->texture.loadFromFile("./Assets/Animations/Hero/IdleRunEW/heroIdleRunEW_tex.png");
	this->factory.loadDragonBonesData("./Assets/Animations/Hero/IdleRunEW/heroIdleRunEW_ske.json");
	this->factory.loadTextureAtlasData("./Assets/Animations/Hero/IdleRunEW/heroIdleRunEW_tex.json", &texture);
	this->armatureIdle = new dragonBones::SFMLArmatureDisplay("ArmatureheroIdle");

	this->armatureIdle->getAnimation()->play("Idle");
	this->armatureIdle->setPosition(sf::Vector2f(posX, posY));

	//RUN_UP:


	//RUN_RIGHT:
	this->factory.clear();
	this->texture.loadFromFile("./Assets/Animations/Hero/IdleRunEW/heroIdleRunEW_tex.png");
	this->factory.loadDragonBonesData("./Assets/Animations/Hero/IdleRunEW/heroIdleRunEW_ske.json");
	this->factory.loadTextureAtlasData("./Assets/Animations/Hero/IdleRunEW/heroIdleRunEW_tex.json", &texture);
	this->armatureRunRight = new dragonBones::SFMLArmatureDisplay("ArmatureheroRunEW");

	this->armatureRunRight->getAnimation()->play("RunEW");
	this->armatureRunRight->setPosition(sf::Vector2f(posX, posY));

	//RUN_DOWN:
	this->texture.loadFromFile("./Assets/Animations/Hero/RunS/heroRunS_tex.png");
	this->factory.loadDragonBonesData("./Assets/Animations/Hero/RunS/heroRunS_ske.json");
	this->factory.loadTextureAtlasData("./Assets/Animations/Hero/RunS/heroRunS_tex.json", &texture);
	this->armatureRunDown = new dragonBones::SFMLArmatureDisplay("ArmatureheroRunS");

	this->armatureRunDown->getAnimation()->play("RunS");
	this->armatureRunDown->setPosition(sf::Vector2f(posX, posY));
	
	//RUN_LEFT:
	this->factory.clear();
	this->texture.loadFromFile("./Assets/Animations/Hero/IdleRunEW/heroIdleRunEW_tex.png");
	this->factory.loadDragonBonesData("./Assets/Animations/Hero/IdleRunEW/heroIdleRunEW_ske.json");
	this->factory.loadTextureAtlasData("./Assets/Animations/Hero/IdleRunEW/heroIdleRunEW_tex.json", &texture);
	this->armatureRunLeft = new dragonBones::SFMLArmatureDisplay("ArmatureheroRunEW");
	this->armatureRunLeft->getArmature()->setFlipX(true);

	
	//ROLL:
		/*

			WIP

		*/
}

dragonBones::SFMLArmatureDisplay* AnimationComponent::playAnimation(int key, const float& dt, float posX, float posY)
{
	switch (key)
	{
	case IDLE:
		
		break;
	case RUN_UP:
		/*

			WIP

		*/
		break;
	case RUN_RIGHT:
		this->armatureRunRight->getAnimation()->play("RunEW");
		this->armatureRunRight->setPosition(sf::Vector2f(posX, posY));
		break;
	case RUN_DOWN:
		this->armatureRunDown->getAnimation()->play("RunS");
		this->armatureRunDown->setPosition(sf::Vector2f(posX, posY));
		break;
	case RUN_LEFT:
		this->armatureRunLeft->getAnimation()->play("RunEW");
		this->armatureRunLeft->setPosition(sf::Vector2f(posX, posY));
		break;
	case ROLL:
		/*

			WIP

		*/
		break;
	}
	return armatureDisplay;
}
