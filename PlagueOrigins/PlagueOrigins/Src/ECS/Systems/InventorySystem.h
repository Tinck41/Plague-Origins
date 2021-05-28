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
	void createInventorySlots(entt::registry& reg, tgui::GuiSFML& gui);
	void createQuickSlots(entt::registry& reg, tgui::GuiSFML& gui);
	void createRingSlots(entt::registry& reg, tgui::GuiSFML& gui);

	void rightClickOnInventorySlot(entt::registry& reg, tgui::Panel::Ptr inventory, tgui::Panel::Ptr panel, tgui::Button::Ptr slot);

	void equipItem(entt::registry& reg, tgui::Panel::Ptr inventory, tgui::Button::Ptr slot);
	void unequipItem(entt::registry& reg, tgui::Panel::Ptr inventory, tgui::Button::Ptr slot);
	void removeItem(entt::registry& reg, tgui::Panel::Ptr inventory, tgui::Button::Ptr slot);
};

