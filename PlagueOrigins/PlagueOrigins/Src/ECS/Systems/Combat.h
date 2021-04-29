#pragma once

#include "IEcsUpdateSystem.h"

#include "Src/ECS/Components.h"

class Combat :
	public IEcsUpdateSystem
{
public:
	virtual void update(entt::registry& reg, const float& dt) override;
private:
	int chooseSector(sf::Vector2f direction);
};