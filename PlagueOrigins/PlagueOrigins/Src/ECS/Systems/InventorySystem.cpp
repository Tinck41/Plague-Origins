#include "stdafx.h"
#include "InventorySystem.h"

InventorySystem::InventorySystem()
{
}

void InventorySystem::onCreate(entt::registry& reg, tgui::GuiSFML& gui)
{
	gui.get<tgui::Panel>("inventoryButtons")->setVisible(false);
	gui.get<tgui::Picture>("unfoldedInventory1")->setVisible(false);
	gui.get<tgui::Picture>("unfoldedInventory2")->setVisible(false);
	gui.get<tgui::Picture>("unfoldedInventory3")->setVisible(false);
	gui.get<tgui::Picture>("unfoldedInventory4")->setVisible(false);
}

void InventorySystem::update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt)
{
	auto view = reg.view<Inventory, PlayerInput>();
	for (auto entity : view) 
	{
		Inventory& inventory = reg.get<Inventory>(entity);
		PlayerInput& playerInput = reg.get<PlayerInput>(entity);
		if (playerInput.escReleased)
		{
			escReleased(inventory);
		}
		if (playerInput.LMBreleased)
		{
			if (gui.get<tgui::Button>("inventoryButton1")->isMouseDown()) buttonClicked(0, inventory);
			if (gui.get<tgui::Button>("inventoryButton2")->isMouseDown()) buttonClicked(1, inventory);
			if (gui.get<tgui::Button>("inventoryButton3")->isMouseDown()) buttonClicked(2, inventory);
			if (gui.get<tgui::Button>("inventoryButton4")->isMouseDown()) buttonClicked(3, inventory);
		}
	}
}

void InventorySystem::render(entt::registry& reg, sf::RenderWindow& window, tgui::GuiSFML& gui)
{
	auto view = reg.view<Inventory>();
	for (auto entity : view)
	{
		Inventory& inventory = reg.get<Inventory>(entity);
		switch (inventory.state)
		{
		case 0:
			gui.get<tgui::Panel>("statusBar")->setVisible(true);
			gui.get<tgui::Panel>("inventoryButtons")->setVisible(false);
			
			gui.get<tgui::Picture>("unfoldedInventory1")->setVisible(false);
			gui.get<tgui::Picture>("unfoldedInventory2")->setVisible(false);
			gui.get<tgui::Picture>("unfoldedInventory3")->setVisible(false);
			gui.get<tgui::Picture>("unfoldedInventory4")->setVisible(false);
			break;
		case 1:
			gui.get<tgui::Panel>("statusBar")->setVisible(false);
			gui.get<tgui::Panel>("inventoryButtons")->setVisible(true);
			
			gui.get<tgui::Picture>("unfoldedInventory1")->setVisible(false);
			gui.get<tgui::Picture>("unfoldedInventory2")->setVisible(false);
			gui.get<tgui::Picture>("unfoldedInventory3")->setVisible(false);
			gui.get<tgui::Picture>("unfoldedInventory4")->setVisible(false);
			break;
		case 2:
			gui.get<tgui::Panel>("statusBar")->setVisible(false);
			gui.get<tgui::Panel>("inventoryButtons")->setVisible(true);
			
			gui.get<tgui::Picture>("unfoldedInventory1")->setVisible(true);
			gui.get<tgui::Picture>("unfoldedInventory2")->setVisible(false);
			gui.get<tgui::Picture>("unfoldedInventory3")->setVisible(false);
			gui.get<tgui::Picture>("unfoldedInventory4")->setVisible(false);
			break;
		case 3:
			gui.get<tgui::Panel>("statusBar")->setVisible(false);
			gui.get<tgui::Panel>("inventoryButtons")->setVisible(true);
			
			gui.get<tgui::Picture>("unfoldedInventory1")->setVisible(false);
			gui.get<tgui::Picture>("unfoldedInventory2")->setVisible(true);
			gui.get<tgui::Picture>("unfoldedInventory3")->setVisible(false);
			gui.get<tgui::Picture>("unfoldedInventory4")->setVisible(false);
			break;
		case 4:
			gui.get<tgui::Panel>("statusBar")->setVisible(false);
			gui.get<tgui::Panel>("inventoryButtons")->setVisible(true);
			
			gui.get<tgui::Picture>("unfoldedInventory1")->setVisible(false);
			gui.get<tgui::Picture>("unfoldedInventory2")->setVisible(false);
			gui.get<tgui::Picture>("unfoldedInventory3")->setVisible(true);
			gui.get<tgui::Picture>("unfoldedInventory4")->setVisible(false);
			break;
		case 5:
			gui.get<tgui::Panel>("statusBar")->setVisible(false);
			gui.get<tgui::Panel>("inventoryButtons")->setVisible(true);
			
			gui.get<tgui::Picture>("unfoldedInventory1")->setVisible(false);
			gui.get<tgui::Picture>("unfoldedInventory2")->setVisible(false);
			gui.get<tgui::Picture>("unfoldedInventory3")->setVisible(false);
			gui.get<tgui::Picture>("unfoldedInventory4")->setVisible(true);
			break;
		default:
			break;
		}
	}
}

void InventorySystem::buttonClicked(int buttonIndex, Inventory& inventory)
{
	inventory.state = buttonIndex + 2;
}

void InventorySystem::escReleased(Inventory& inventory)
{
	if (inventory.state == 0) inventory.state = 1;
	else inventory.state = 0;
}
