#pragma once

#include "IUpdateSystem.h"
#include "IRenderSystem.h"
#include "IOnDestroySystem.h"
#include "Src/ECS/Components.h"

class Physics :
	public IUpdateSystem,
	public IRenderSystem,
	public IOnDestroySystem
{
	virtual void update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt) override;

	virtual void render(entt::registry& reg, sf::RenderWindow& window, tgui::GuiSFML& gui) override;

	virtual void onDestroy(entt::registry& reg, tgui::GuiSFML& gui) override;
};