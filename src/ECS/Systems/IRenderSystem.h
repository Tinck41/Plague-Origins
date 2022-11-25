#pragma once

#include "entt.hpp"

class IRenderSystem
{
public:
	virtual void render(entt::registry& reg, sf::RenderWindow& window, tgui::GuiSFML& gui) = 0;
};