#include "stdafx.h"
#include "InventorySystem.h"

InventorySystem::InventorySystem()
{
}

void InventorySystem::onCreate(entt::registry& reg, tgui::GuiSFML& gui)
{
	gui.get<tgui::Panel>("menuButtons")->get<tgui::Button>("inventoryButton")->onClick(&InventorySystem::unfoldInventory, this, std::ref(gui));

	createInventorySlots(gui);
	createQuickSlots(gui);
	createRingSlots(gui);
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
	auto view = reg.view<Inventory, PlayerInput>();
	for (auto entity : view)
	{
		Inventory& inventory = reg.get<Inventory>(entity);
		tgui::Panel::Ptr inventoryPanel = gui.get<tgui::Panel>("unfoldedInventory");

		if (inventoryPanel->isVisible())
		{
			tgui::Panel::Ptr miniInventory	= inventoryPanel->get<tgui::Panel>("miniInventory");
			tgui::Panel::Ptr quickSlots		= inventoryPanel->get<tgui::Panel>("quickSlots");
			tgui::Panel::Ptr ringSlots		= inventoryPanel->get<tgui::Panel>("ringSlots");

			for (size_t i = 0; i < inventory.items.size(); i++)
			{
				Icon& icon = reg.get<Icon>(entt::entity(inventory.items[i]));
				Item& item = reg.get<Item>(entt::entity(inventory.items[i]));

				tgui::Button::Ptr slot;

				std::stringstream ss;
				std::string name;
				ss << i;
				ss >> name;

				if (item.isEquiped)
				{
					if (item.type == RING)
					{
						slot = ringSlots->get<tgui::Button>(name);
					}
					else if (item.type == BOOSTER)
					{
						slot = quickSlots->get<tgui::Button>(name);
					}
				}
				else
				{
					slot = miniInventory->get<tgui::Button>(name);
				}

				Description& description = reg.get<Description>(entt::entity(inventory.items[i]));

				if (slot->isMouseDown())
				{
					inventoryPanel->get<tgui::Label>("itemName")->setText(item.name);
					inventoryPanel->get<tgui::Label>("itemDescription")->setText(description.description);
				}

				slot->getRenderer()->setTexture(icon.image);
			}
		}
	}
}

void InventorySystem::unfoldInventory(tgui::GuiSFML& gui)
{
	bool isVisable = gui.get<tgui::Panel>("unfoldedInventory")->isVisible();

	gui.get<tgui::Panel>("unfoldedInventory")->setVisible(!isVisable);

	gui.get<tgui::Label>("itemName")->setText("");
	gui.get<tgui::Label>("itemDescription")->setText("");

	gui.get<tgui::Panel>("itemActions")->setVisible(false);
}

void InventorySystem::createInventorySlots(tgui::GuiSFML& gui)
{
	tgui::Panel::Ptr inventory = gui.get<tgui::Panel>("unfoldedInventory");
	tgui::Panel::Ptr panel = inventory->get<tgui::Panel>("miniInventory");

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
			
			int k = config.inventorySlots.x * i + j;
			std::stringstream ss;
			std::string name;
			ss << k;
			ss >> name;
			panel->add(slot, name);

			slot->onRightMouseRelease(&InventorySystem::rightClickOnInventorySlot, this, inventory, panel, slot);
		}
	}
}

void InventorySystem::createQuickSlots(tgui::GuiSFML& gui)
{
	tgui::Panel::Ptr inventory = gui.get<tgui::Panel>("unfoldedInventory");
	tgui::Panel::Ptr panel = inventory->get<tgui::Panel>("quickAction");

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

			slot->onRightMouseRelease(&InventorySystem::rightClickOnInventorySlot, this, inventory, panel, slot);
		}
	}
}

void InventorySystem::createRingSlots(tgui::GuiSFML& gui)
{
	tgui::Panel::Ptr inventory = gui.get<tgui::Panel>("unfoldedInventory");
	tgui::Panel::Ptr panel = inventory->get<tgui::Panel>("ringEquiped");

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

			panel->add(slot, std::to_string(int(config.ringSlots.x * i + j)));

			slot->onRightMouseRelease(&InventorySystem::rightClickOnInventorySlot, this, inventory, panel, slot);
		}
	}
}

void InventorySystem::rightClickOnInventorySlot(tgui::Panel::Ptr inventory, tgui::Panel::Ptr panel, tgui::Button::Ptr slot)
{
	auto itemActions = inventory->get<tgui::Panel>("itemActions");
	bool isVisable = itemActions->isVisible();

	float x = panel->getPosition().x + slot->getPosition().x + config.slotSize.x;
	float y = panel->getPosition().y + slot->getPosition().y;

	itemActions->setPosition(x, y);

	if (panel->getWidgetName() == "miniInventory")
	{
		auto btn = itemActions->get<tgui::Button>("Button1");

		btn->setText("Equip");
		btn->onMouseRelease(&InventorySystem::equipItem, this, inventory, slot);
	}
	else
	{
		itemActions->get<tgui::Button>("Button1")->setText("Unequip");
	}
	itemActions->get<tgui::Button>("Button2")->setText("idk");
	itemActions->get<tgui::Button>("Button3")->setText("Remove");

	inventory->get<tgui::Panel>("itemActions")->setVisible(!isVisable);
}

void InventorySystem::equipItem(tgui::Panel::Ptr inventory, tgui::Button::Ptr slot)
{
}
