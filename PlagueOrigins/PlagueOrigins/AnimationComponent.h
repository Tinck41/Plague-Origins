#pragma once

#include "PlayerAnimationStates.h"

class AnimationComponent
{
private:
	//Variables
	bool done;
	int state;

	animationName currentAnimation;
	sf::Vector2f currentDirection = sf::Vector2f(0.f, 1.f);

	//Game objects
	sf::Texture texture;
	sf::RectangleShape& shape;
	dragonBones::SFMLFactory factory;
	const dragonBones::SFMLFactory* zf = dragonBones::SFMLFactory::get();
	dragonBones::SFMLArmatureDisplay* armatureDisplay;

	void playAnimation();
	void playMovementAnimation();
	void playIdleAnimation();
	void playAttackAnimation();
public:
	//Constructor/Destructor
	//AnimationComponent(sf::RectangleShape& shape, dragonBones::SFMLFactory& factory);
	AnimationComponent(sf::RectangleShape& shape);
	~AnimationComponent();

	//Functions
	void initArmature(sf::Vector2f vec);
	void updateFactory(float dt);

	void setAnimation(animationName newAnimation, sf::Vector2f newDirection);
	void setAnimation(animationName newAnimation);

	// Getters
	dragonBones::SFMLArmatureDisplay* getArmatureDisplay() 
	{ 
		return this->armatureDisplay; 
	}
};