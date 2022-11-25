#pragma once

#include "Systems.h"
#include "entt.hpp"

class SystemHandler
{
private:
	std::vector<IUpdateSystem*> updatableSystems;
	std::vector<IRenderSystem*> renderableSystems;
	std::vector<IOnCreateSystem*> onCreateSystems;
	std::vector<IOnDestroySystem*> onDestroySystems;
public:
	SystemHandler();
	~SystemHandler();

	void onCreate(entt::registry& reg, tgui::GuiSFML& gui);
	void update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt);
	void render(entt::registry& reg, sf::RenderWindow& window, tgui::GuiSFML& gui);
	void onDestroy(entt::registry& reg, tgui::GuiSFML& gui);
};