#pragma once

#include "Src/ECS/Systems/IEcsRenderSystem.h"

class Camera :
	public IEcsRenderSystem
{
	virtual void render(entt::registry& reg, sf::RenderWindow& window) override;
};