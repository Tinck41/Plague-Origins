#pragma once

#include "ECS/Systems/IRenderSystem.h"
#include "ECS/Systems/IUpdateSystem.h"

#include "ECS/Components.h"

class Camera :
	public IRenderSystem,
	public IUpdateSystem
{
	virtual void update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt) override;

	virtual void render(entt::registry& reg, sf::RenderWindow& window, tgui::GuiSFML& gui) override;
};