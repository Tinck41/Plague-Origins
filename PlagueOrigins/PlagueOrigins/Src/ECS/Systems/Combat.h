#pragma once
#include "IUpdateSystem.h"

#include "Src/ECS/Components.h"

#define RADTODEG 180.f / M_PI

class Combat :
	public IUpdateSystem
{
public:
	virtual void update(entt::registry& reg, const float& dt) override;
private:
	float angleBetween(const sf::Vector2f& vec1, const sf::Vector2f& vec2);
};