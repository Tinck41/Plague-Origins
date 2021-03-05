#pragma once

#include "PlayerStates.h"

class AnimationComponent
{
private:
	//Variables
	bool done;
	int state;

	unsigned curState;

	//Game objects
	sf::Texture texture;
	sf::RectangleShape& shape;
	dragonBones::SFMLFactory& factory;
	dragonBones::SFMLArmatureDisplay* armatureDisplay;

	void setMovementAnimation(unsigned state);
	void setIdleAnimation(unsigned state);
public:
	//Constructor/Destructor
	AnimationComponent(sf::RectangleShape& shape, dragonBones::SFMLFactory& factory);
	~AnimationComponent();

	//Functions
	void initArmature(sf::Vector2f vec);

	dragonBones::SFMLArmatureDisplay* playAnimation(unsigned globalState, unsigned localState);

};