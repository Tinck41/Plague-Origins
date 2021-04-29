#pragma once

#include "Systems.h"
#include "entt.hpp"

class SystemHandler
{
private:
	std::vector<IEcsUpdateSystem*> updatableSystems;
	std::vector<IEcsRenderSystem*> renderableSystems;
	std::vector<IEcsOnCreateUpdate*> onCreateSystems;
public:
	SystemHandler();
	~SystemHandler();

	void onCreate(entt::registry& reg);
	void update(entt::registry& reg, const float& dt);
	void render(entt::registry& reg, sf::RenderWindow& window);
};