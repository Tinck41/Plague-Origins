#pragma once
#include "IUpdateSystem.h"
#include "IRenderSystem.h"
#include "IOnCreateSystem.h"
#include "Src/ECS/Components.h"

class InventorySystem :
	public IUpdateSystem,
	public IRenderSystem,
	public IOnCreateSystem
{
private:
	void buttonClicked(int buttonIndex, Inventory& inventory);
	void escReleased(Inventory& inventory);
public:
	InventorySystem();
	virtual void update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt) override;
	virtual void render(entt::registry& reg, sf::RenderWindow& window, tgui::GuiSFML& gui) override;
	virtual void onCreate(entt::registry& reg, tgui::GuiSFML& gui) override;
};

