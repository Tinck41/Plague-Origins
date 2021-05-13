#pragma once
#include "IUpdateSystem.h"
#include "IRenderSystem.h"
#include "Src/ECS/Components.h"

class InventorySystem :
	public IUpdateSystem,
	public IRenderSystem
{
public:
	InventorySystem();
	virtual void update(entt::registry& reg, const float& dt) override;
	virtual void render(entt::registry& reg, sf::RenderWindow& window, tgui::GuiSFML& gui) override;
};

