#include "stdafx.h"
#include "InventorySystem.h"

InventorySystem::InventorySystem()
{
}

void InventorySystem::onCreate(entt::registry& reg, tgui::GuiSFML& gui)
{
	gui.get<tgui::Panel>("menuButtons")->get<tgui::Button>("inventoryButton")->onClick(&InventorySystem::unfoldInventory, this, std::ref(gui));

	tgui::Panel::Ptr inventoryPanel = gui.get<tgui::Panel>("unfoldedInventory");

	tgui::Panel::Ptr miniInventory	= inventoryPanel->get<tgui::Panel>("miniInventory");
	tgui::Panel::Ptr quickAction	= inventoryPanel->get<tgui::Panel>("quickAction");
	tgui::Panel::Ptr ringEquiped	= inventoryPanel->get<tgui::Panel>("ringEquiped");

	createInventorySlots(miniInventory);
	createQuickSlots(quickAction);
	createRingSlots(ringEquiped);
}

void InventorySystem::update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt)
{
	auto view = reg.view<Inventory>();
	for (auto entity : view) 
	{

	}
}

void InventorySystem::render(entt::registry& reg, sf::RenderWindow& window, tgui::GuiSFML& gui)
{
	auto view = reg.view<Inventory>();
	for (auto entity : view)
	{

	}
}

void InventorySystem::unfoldInventory(tgui::GuiSFML& gui)
{
	bool isVisable = gui.get<tgui::Panel>("unfoldedInventory")->isVisible();

	gui.get<tgui::Panel>("unfoldedInventory")->setVisible(!isVisable);
}

void InventorySystem::createInventorySlots(tgui::Panel::Ptr panel)
{
	for (int i = 0; i < config.inventorySlots.y; i++)
	{
		for (int j = 0; j < config.inventorySlots.x; j++)
		{
			tgui::Button::Ptr slot = tgui::Button::create();

			slot->getRenderer()->setBackgroundColor(tgui::Color::Transparent);
			slot->getRenderer()->setBackgroundColorHover(tgui::Color(0, 0, 0, 101));
			slot->getRenderer()->setBackgroundColorDown(tgui::Color(0, 0, 0, 201));
			slot->getRenderer()->setBorders(tgui::Borders(0.f));

			slot->setSize(config.slotSize.x, config.slotSize.y);
			slot->setPosition(config.slotSize.x * j + config.slotMargin.x * j, config.slotSize.y * i + config.slotMargin.y * i);

			panel->add(slot, std::to_string(config.inventorySlots.x * i + j));
		}
	}
}

void InventorySystem::createQuickSlots(tgui::Panel::Ptr panel)
{
	for (int i = 0; i < config.quickSlots.y; i++)
	{
		for (int j = 0; j < config.quickSlots.x; j++)
		{
			tgui::Button::Ptr slot = tgui::Button::create();

			slot->getRenderer()->setBackgroundColor(tgui::Color::Transparent);
			slot->getRenderer()->setBackgroundColorHover(tgui::Color(0, 0, 0, 101));
			slot->getRenderer()->setBackgroundColorDown(tgui::Color(0, 0, 0, 201));
			slot->getRenderer()->setBorders(tgui::Borders(0.f));

			slot->setSize(config.slotSize.x, config.slotSize.y);
			slot->setPosition(config.slotSize.x * j + config.slotMargin.x * j, config.slotSize.y * i + config.slotMargin.y * i);

			panel->add(slot, std::to_string(config.quickSlots.x * i + j));
		}
	}
}

void InventorySystem::createRingSlots(tgui::Panel::Ptr panel)
{
	for (int i = 0; i < config.ringSlots.y; i++)
	{
		for (int j = 0; j < config.ringSlots.x; j++)
		{
			tgui::Button::Ptr slot = tgui::Button::create();

			slot->getRenderer()->setBackgroundColor(tgui::Color::Transparent);
			slot->getRenderer()->setBackgroundColorHover(tgui::Color(0, 0, 0, 101));
			slot->getRenderer()->setBackgroundColorDown(tgui::Color(0, 0, 0, 201));
			slot->getRenderer()->setBorders(tgui::Borders(0.f));

			slot->setSize(config.slotSize.x, config.slotSize.y);
			slot->setPosition(config.slotSize.x * j + config.slotMargin.x * j, config.slotSize.y * i + config.slotMargin.y * i);

			panel->add(slot, std::to_string(config.ringSlots.x * i + j));
		}
	}
}
