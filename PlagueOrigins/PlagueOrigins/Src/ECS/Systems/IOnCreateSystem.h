#pragma once

#include "entt.hpp"
#include "SFML/Graphics.hpp"

class IOnCreateSystem
{
public:
	virtual void onCreate(entt::registry& reg, tgui::GuiSFML& gui) = 0;
};