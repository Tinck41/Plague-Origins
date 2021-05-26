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

	void createInventorySlots(tgui::GuiSFML& gui);
	void createQuickSlots(tgui::GuiSFML& gui);
	void createRingSlots(tgui::GuiSFML& gui);

	void rightClickOnInventorySlot(tgui::Panel::Ptr inventory, tgui::Panel::Ptr panel, tgui::Button::Ptr slot);

	void equipItem(tgui::Panel::Ptr inventory, tgui::Button::Ptr slot);
	void unequipItem();
};

