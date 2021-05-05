#pragma once

#include "Src/ECS/Systems/IEcsRenderSystem.h"
#include "Src/ECS/Systems/IEcsUpdateSystem.h"

#include "Src/ECS/Components.h"

class Camera :
	public IEcsRenderSystem,
	public IEcsUpdateSystem
{
	virtual void update(entt::registry& reg, const float& dt) override;

	virtual void render(entt::registry& reg, sf::RenderWindow& window) override;
};