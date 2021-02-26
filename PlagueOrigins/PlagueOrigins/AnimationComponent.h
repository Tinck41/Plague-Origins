#pragma once

#include <dragonBones/SFMLFactory.h>
#include <dragonBones/SFMLArmatureDisplay.h>

#include "stdafx.h"

class AnimationComponent
{
private:
	
	//Variables
	bool done;
	int state;
	enum key
	{
		IDLE, RUN_UP, RUN_LEFT, RUN_DOWN, RUN_RIGHT, ROLL
	};

	//Game objects
	sf::Texture texture;
	sf::RectangleShape shape;
	dragonBones::SFMLFactory& factory;
	dragonBones::SFMLArmatureDisplay* armatureIdle;
	dragonBones::SFMLArmatureDisplay* armatureRunUp;
	dragonBones::SFMLArmatureDisplay* armatureRunRight;
	dragonBones::SFMLArmatureDisplay* armatureRunDown;
	dragonBones::SFMLArmatureDisplay* armatureRunLeft;
	dragonBones::SFMLArmatureDisplay* armatureRoll;

public:
	//Constructor/Destructor
	AnimationComponent(sf::RectangleShape shape, dragonBones::SFMLFactory& factory);
	~AnimationComponent();

	//Accessors
	const bool& isDone() const;

	//Functions
	dragonBones::SFMLArmatureDisplay* initAnimation(int key, float posX, float posY);

	dragonBones::SFMLArmatureDisplay* playAnimation(int key, const float& dt, float posX, float posY);

};