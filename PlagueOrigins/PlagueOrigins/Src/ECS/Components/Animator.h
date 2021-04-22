#pragma once

#include <string>
#include "PlayerAnimationStates.h"
#include "SFML/Graphics.hpp"

#include <dragonBones/SFMLFactory.h>
#include <dragonBones/SFMLArmatureDisplay.h>

struct Animator
{
	std::string prefix;
	std::string armatureName;
	std::string postfix;

	animationName currentAnimation;
	sf::Vector2f currentDirection = sf::Vector2f(0.f, 1.f);

	dragonBones::SFMLArmatureDisplay* armatureDisplay;
};