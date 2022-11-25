#pragma once

#include "IUpdateSystem.h"
#include "IRenderSystem.h"

#include "ECS/Components.h"

class StaminaSystem :
	public IUpdateSystem,
	public IRenderSystem
{
	virtual void update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt) override;

	virtual void render(entt::registry& reg, sf::RenderWindow& window, tgui::GuiSFML& gui) override;
};