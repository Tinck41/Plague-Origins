#pragma once

#include "Systems.h"
#include "entt.hpp"

class SystemHandler
{
private:
	std::vector<IUpdateSystem*> updatableSystems;
	std::vector<IRenderSystem*> renderableSystems;
	std::vector<IOnCreateSystem*> onCreateSystems;
public:
	SystemHandler();
	~SystemHandler();

	void onCreate(entt::registry& reg);
	void update(entt::registry& reg, const float& dt);
	void render(entt::registry& reg, sf::RenderWindow& window, tgui::GuiSFML& gui);
};