#pragma once

#include "Src/ECS/Systems/IRenderSystem.h"
#include "Src/ECS/Systems/IUpdateSystem.h"

#include "Src/ECS/Components.h"

class Camera :
	public IRenderSystem,
	public IUpdateSystem
{
	virtual void update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt) override;

	virtual void render(entt::registry& reg, sf::RenderWindow& window, tgui::GuiSFML& gui) override;
};