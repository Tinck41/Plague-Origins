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
		NONE, IDLE, RUN_UP, RUN_LEFT, RUN_DOWN, RUN_RIGHT, ROLL
	};

	//Game objects
	sf::Texture texture;
	sf::RectangleShape& shape;
	dragonBones::SFMLFactory& factory;
	dragonBones::SFMLArmatureDisplay* armatureDisplay;


public:
	//Constructor/Destructor
	AnimationComponent(sf::RectangleShape& shape, dragonBones::SFMLFactory& factory);
	~AnimationComponent();

	//Functions
	void initArmature(sf::Vector2f vec);

	dragonBones::SFMLArmatureDisplay* playAnimation(int key, float posX, float posY);

};