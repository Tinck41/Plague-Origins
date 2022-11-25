#pragma once

#include "PlayerAnimationStates.h"
#include "SFML/Graphics.hpp"

#include <string>
#include <dragonBones/SFMLFactory.h>
#include <dragonBones/SFMLArmatureDisplay.h>

struct Animator
{
	Animator(float scale)
	{
		currentAnimation = NONE;
		previousAnimation = NONE;
		previousFaceDirection = sf::Vector2f(0.f, 1.f);
		currentFaceDirection = sf::Vector2f(0.f, 1.f);
		this->scale = scale;

		currentAnimationDuration = 0.f;
	}
	std::string postfix;

	animationName currentAnimation;
	animationName previousAnimation;
	sf::Vector2f previousFaceDirection;
	sf::Vector2f currentFaceDirection;

	dragonBones::SFMLArmatureDisplay* armatureDisplay;

	float scale;
	sf::RenderStates states;

	sf::Int32 currentAnimationDuration;
	sf::Int32 currentAnimationDurationLeft;
};