#pragma once

#include <SFML/Graphics.hpp>
#include <entt.hpp>
#include <box2d/box2d.h>

struct BossFightArena
{
	std::vector<uint32_t> doors;

	bool bossIsDead		= false;
	bool playerIsDead	= false;
	bool arenaClosed	= false;
};