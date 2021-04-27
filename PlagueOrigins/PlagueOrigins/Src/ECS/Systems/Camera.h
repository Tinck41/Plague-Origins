#pragma once

#include "Src/ECS/Systems/IEcsRenderSystem.h"

#include "Src/ECS/Components.h"

class Camera :
	public IEcsRenderSystem
{
	virtual void render(entt::registry& reg, sf::RenderWindow& window) override;
};