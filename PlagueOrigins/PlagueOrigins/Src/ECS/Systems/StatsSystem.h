#pragma once

#include "IUpdateSystem.h"
#include "IRenderSystem.h"

#include "Src/ECS/Components.h"

class StatsSystem :
	public IUpdateSystem,
	public IRenderSystem
{
public:
	virtual void update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt) override;
	virtual void render(entt::registry& reg, sf::RenderWindow& window, tgui::GuiSFML& gui) override;

	void increaseChar(Stats& stats, int value, charName charName);
	void decreaseChar(Stats& stats, int value, charName charName);
};