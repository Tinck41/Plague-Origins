#pragma once

#include "Systems/IEcsRenderSystem.h"
#include "Systems/IEcsUpdateSystem.h"

#include "entt.hpp"

class SystemHandler
{
private:
	std::vector<IEcsUpdateSystem*> updatableSystems;
	std::vector<IEcsRenderSystem*> renderableSystems;
public:
	SystemHandler();
	~SystemHandler();

	void update(entt::registry& reg, const float& dt);
	void render(entt::registry& reg, sf::RenderWindow& window);
};