//#include "AnimationComponent.h"
//
////Constructor/Destructor
//AnimationComponent::AnimationComponent(sf::RectangleShape shape, dragonBones::SFMLFactory& factory) :
//	factory(factory)
//{
//	this->shape = shape;
//}
//
//AnimationComponent::~AnimationComponent()
//{
//}
//
//
//const bool& AnimationComponent::isDone() const
//{
//	return true;
//	// TODO: insert return statement here
//}
//
//void AnimationComponent::initArmatures()
//{
//	//IDLE:
//
//	this->texture.loadFromFile("./Assets/Animations/Hero/IdleRunEW/heroIdleRunEW_tex.png");
//
//	this->factory.clear();
//	this->factory.loadDragonBonesData("./Assets/Animations/Hero/IdleRunEW/heroIdleRunEW_ske.json");
//	this->factory.loadTextureAtlasData("./Assets/Animations/Hero/IdleRunEW/heroIdleRunEW_tex.json", &texture);
//
//	this->armatureDefault = new dragonBones::SFMLArmatureDisplay("ArmatureheroIdle");
//	this->armatureIdle = this->armatureDefault;
//	this->armatureDefault->getArmature()->dispose();
//	//RUN_UP:
//	this->texture.loadFromFile("./Assets/Animations/Hero/RunN/heroRunN_tex.png");
//
//	this->factory.clear();
//	this->factory.loadDragonBonesData("./Assets/Animations/Hero/RunN/heroRunN_ske.json");
//	this->factory.loadTextureAtlasData("./Assets/Animations/Hero/RunN/heroRunN_tex.json", &texture);
//
//	this->armatureRunUp = new dragonBones::SFMLArmatureDisplay("ArmatureheroRunN");
//	//RUN_RIGHT:
//	this->texture.loadFromFile("./Assets/Animations/Hero/IdleRunEW/heroIdleRunEW_tex.png");
//
//	this->factory.clear();
//	this->factory.loadDragonBonesData("./Assets/Animations/Hero/IdleRunEW/heroIdleRunEW_ske.json");
//	this->factory.loadTextureAtlasData("./Assets/Animations/Hero/IdleRunEW/heroIdleRunEW_tex.json", &texture);
//
//	this->armatureRunRight = new dragonBones::SFMLArmatureDisplay("ArmatureheroRunEW");
//	//RUN_DOWN:
//	this->texture.loadFromFile("./Assets/Animations/Hero/RunS/heroRunS_tex.png");
//
//	this->factory.clear();
//	this->factory.loadDragonBonesData("./Assets/Animations/Hero/RunS/heroRunS_ske.json");
//	this->factory.loadTextureAtlasData("./Assets/Animations/Hero/RunS/heroRunS_tex.json", &texture);
//
//	this->armatureRunDown = new dragonBones::SFMLArmatureDisplay("ArmatureheroRunS");
//	//RUN_LEFT:
//	this->texture.loadFromFile("./Assets/Animations/Hero/IdleRunEW/heroIdleRunEW_tex.png");
//
//	this->factory.clear();
//	this->factory.loadDragonBonesData("./Assets/Animations/Hero/IdleRunEW/heroIdleRunEW_ske.json");
//	this->factory.loadTextureAtlasData("./Assets/Animations/Hero/IdleRunEW/heroIdleRunEW_tex.json", &texture);
//
//	this->armatureRunLeft = new dragonBones::SFMLArmatureDisplay("ArmatureheroRunEW");
//	this->armatureRunLeft->getArmature()->setFlipX(true);
//	//ROLL:
//		/*
//			WIP
//		*/
//}
//
//dragonBones::SFMLArmatureDisplay* AnimationComponent::playAnimation(int key, const float& dt, float posX, float posY)
//{
//	switch (key)
//	{
//	case IDLE:
//		//this->factory.clear();
//		//this->factory.loadDragonBonesData("./Assets/Animations/Hero/IdleRunEW/heroIdleRunEW_ske.json");
//		//this->factory.loadTextureAtlasData("./Assets/Animations/Hero/IdleRunEW/heroIdleRunEW_tex.json", &texture);
//
//		this->armatureIdle->getAnimation()->play("Idle");
//		this->armatureIdle->setPosition(sf::Vector2f(posX, posY));
//		return armatureIdle;
//	case RUN_UP:
//		//this->factory.clear();
//		//this->factory.loadDragonBonesData("./Assets/Animations/Hero/RunN/heroRunN_ske.json");
//		//this->factory.loadTextureAtlasData("./Assets/Animations/Hero/RunN/heroRunN_tex.json", &texture);
//
//		this->armatureRunUp->getAnimation()->play("RunN");
//		this->armatureRunUp->setPosition(sf::Vector2f(posX, posY));
//		return armatureRunUp;
//	case RUN_RIGHT:
//		//this->factory.clear();
//		//this->factory.loadDragonBonesData("./Assets/Animations/Hero/IdleRunEW/heroIdleRunEW_ske.json");
//		//this->factory.loadTextureAtlasData("./Assets/Animations/Hero/IdleRunEW/heroIdleRunEW_tex.json", &texture);
//
//		this->armatureRunRight->getAnimation()->play("RunEW");
//		this->armatureRunRight->setPosition(sf::Vector2f(posX, posY));
//		return armatureRunRight;
//	case RUN_DOWN:
//		//this->factory.clear();
//		//this->factory.loadDragonBonesData("./Assets/Animations/Hero/RunS/heroRunS_ske.json");
//		//this->factory.loadTextureAtlasData("./Assets/Animations/Hero/RunS/heroRunS_tex.json", &texture);
//
//		this->armatureRunDown->getAnimation()->play("RunS");
//		this->armatureRunDown->setPosition(sf::Vector2f(posX, posY));
//		return armatureRunDown;
//	case RUN_LEFT:
//		//this->factory.clear();
//		//this->factory.loadDragonBonesData("./Assets/Animations/Hero/IdleRunEW/heroIdleRunEW_ske.json");
//		//this->factory.loadTextureAtlasData("./Assets/Animations/Hero/IdleRunEW/heroIdleRunEW_tex.json", &texture);
//
//		this->armatureRunLeft->getAnimation()->play("RunEW");
//		this->armatureRunLeft->setPosition(sf::Vector2f(posX, posY));
//		return armatureRunLeft;
//	case ROLL:
//		/*
//
//			WIP
//
//		*/
//		break;
//	}
//
//}
