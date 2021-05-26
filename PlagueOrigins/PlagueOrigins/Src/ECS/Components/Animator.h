#pragma once

#include "PlayerAnimationStates.h"
#include "SFML/Graphics.hpp"

#include <string>
#include <dragonBones/SFMLFactory.h>
#include <dragonBones/SFMLArmatureDisplay.h>

struct Animator
{
	std::string postfix;

	animationName currentAnimation = NONE;
	animationName previousAnimation = NONE;
	sf::Vector2f previousFaceDirection = sf::Vector2f(0.f, 1.f);
	sf::Vector2f currentFaceDirection = sf::Vector2f(0.f, 1.f);

	dragonBones::SFMLArmatureDisplay* armatureDisplay;

	float scale = 0.2f;
	sf::RenderStates states;

	float currentAnimationDuration = 0.f;
	sf::Time currentAnimationDurationLeft;
};