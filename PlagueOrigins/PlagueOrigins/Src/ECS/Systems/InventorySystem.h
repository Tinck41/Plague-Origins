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
public:
	InventorySystem();
	virtual void onCreate(entt::registry& reg, tgui::GuiSFML& gui) override;
	virtual void update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt) override;
	virtual void render(entt::registry& reg, sf::RenderWindow& window, tgui::GuiSFML& gui) override;
private:
	void unfoldInventory(tgui::GuiSFML& gui);

	void createInventorySlots(tgui::Panel::Ptr panel);
	void createQuickSlots(tgui::Panel::Ptr panel);
	void createRingSlots(tgui::Panel::Ptr panel);

	void onMouseRelease(entt::registry& reg, tgui::GuiSFML& gui);
};

