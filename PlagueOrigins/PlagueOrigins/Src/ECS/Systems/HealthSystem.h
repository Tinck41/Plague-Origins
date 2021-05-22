#pragma once

#include "IUpdateSystem.h"
#include "IRenderSystem.h"

#include "Src/ECS/Components.h"

class HealthSystem  :
	public IUpdateSystem,
	public IRenderSystem
{
	virtual void update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt) override;

	virtual void render(entt::registry& reg, sf::RenderWindow& window, tgui::GuiSFML& gui) override;
};