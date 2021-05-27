#include "stdafx.h"
#include "InventorySystem.h"

InventorySystem::InventorySystem()
{
}

void InventorySystem::onCreate(entt::registry& reg, tgui::GuiSFML& gui)
{
	gui.get<tgui::Panel>("menuButtons")->get<tgui::Button>("inventoryButton")->onClick(&InventorySystem::unfoldInventory, this, std::ref(gui));

	createInventorySlots(reg, gui);
	createQuickSlots(reg, gui);
	createRingSlots(reg, gui);
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
			tgui::Panel::Ptr quickSlots		= inventoryPanel->get<tgui::Panel>("quickAction");
			tgui::Panel::Ptr ringSlots		= inventoryPanel->get<tgui::Panel>("ringEquiped");

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

			for (size_t i = 0; i < inventory.ringSlots.size(); i++)
			{
				Icon& icon = reg.get<Icon>(entt::entity(inventory.ringSlots[i]));
				Item& item = reg.get<Item>(entt::entity(inventory.ringSlots[i]));

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

				Description& description = reg.get<Description>(entt::entity(inventory.ringSlots[i]));

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

void InventorySystem::createInventorySlots(entt::registry& reg, tgui::GuiSFML& gui)
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

			slot->onRightMouseRelease(&InventorySystem::rightClickOnInventorySlot, this, std::ref(reg), inventory, panel, slot);
		}
	}
}

void InventorySystem::createQuickSlots(entt::registry& reg, tgui::GuiSFML& gui)
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

			int k = config.quickSlots.x * i + j;
			std::stringstream ss;
			std::string name;
			ss << k;
			ss >> name;
			panel->add(slot, name);

			slot->onRightMouseRelease(&InventorySystem::rightClickOnInventorySlot, this, std::ref(reg), inventory, panel, slot);
		}
	}
}

void InventorySystem::createRingSlots(entt::registry& reg, tgui::GuiSFML& gui)
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

			int k = config.ringSlots.x * i + j;
			std::stringstream ss;
			std::string name;
			ss << k;
			ss >> name;
			panel->add(slot, name);

			slot->onRightMouseRelease(&InventorySystem::rightClickOnInventorySlot, this, std::ref(reg), inventory, panel, slot);
		}
	}
}

void InventorySystem::rightClickOnInventorySlot(entt::registry& reg, tgui::Panel::Ptr inventory, tgui::Panel::Ptr panel, tgui::Button::Ptr slot)
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
		btn->onMouseRelease.disconnectAll();
		btn->onMouseRelease(&InventorySystem::equipItem, this, std::ref(reg), inventory, slot);
	}
	else
	{
		auto btn = itemActions->get<tgui::Button>("Button1");

		btn->setText("Unequip");
		btn->onMouseRelease.disconnectAll();
		btn->onMouseRelease(&InventorySystem::unequipItem, this, std::ref(reg), inventory, slot);
	}
	itemActions->get<tgui::Button>("Button2")->setText("idk");
	itemActions->get<tgui::Button>("Button3")->setText("Remove");
	itemActions->get<tgui::Button>("Button3")->onMouseRelease.disconnectAll();
	itemActions->get<tgui::Button>("Button3")->onMouseRelease(&InventorySystem::removeItem, this, std::ref(reg), inventory, slot);

	inventory->get<tgui::Panel>("itemActions")->setVisible(!isVisable);
}

void InventorySystem::equipItem(entt::registry& reg, tgui::Panel::Ptr inventory, tgui::Button::Ptr slot)
{
	inventory->get<tgui::Panel>("itemActions")->setVisible(false);
	
	uint32_t itemId = std::stoi(std::string(slot->getWidgetName()));

	std::stringstream ss;
	std::string name;
	ss << itemId + 1;
	ss >> name;
	
	slot->getRenderer()->setTexture({});

	auto veiw = reg.view<Inventory, PlayerInput>();
	for (auto entity : veiw)
	{
		Inventory& inventoryComp = reg.get<Inventory>(entity);
		if (itemId >= inventoryComp.items.size()) return;
		Item& item = reg.get<Item>(entt::entity(inventoryComp.items[itemId]));

		item.isEquiped = true;

		if (item.type == RING)
		{
			inventoryComp.ringSlots.push_back(inventoryComp.items[itemId]);
		}
		else if (item.type == BOOSTER)
		{
			inventoryComp.quickSlots.push_back(inventoryComp.items[itemId]);
		}

		inventoryComp.items.erase(inventoryComp.items.begin() + itemId, inventoryComp.items.begin() + itemId + 1);

		if (itemId + 1 < config.inventorySlots.x * config.inventorySlots.y)
		{
			inventory->get<tgui::Panel>("miniInventory")->get<tgui::Button>(name)->getRenderer()->setTexture({});
		}

		break;
	}
}

void InventorySystem::unequipItem(entt::registry& reg, tgui::Panel::Ptr inventory, tgui::Button::Ptr slot)
{
	inventory->get<tgui::Panel>("itemActions")->setVisible(false);

	uint32_t itemId = std::stoi(std::string(slot->getWidgetName()));

	std::stringstream ss;
	std::string name;
	ss << itemId + 1;
	ss >> name;

	std::string parentName = std::string(slot->getParent()->getWidgetName());
	slot->getRenderer()->setTexture({});

	auto veiw = reg.view<Inventory, PlayerInput>();
	for (auto entity : veiw)
	{
		Inventory& inventoryComp = reg.get<Inventory>(entity);
		if (parentName == "quickAction")
		{
			if (itemId >= inventoryComp.quickSlots.size()) return;
			Item& item = reg.get<Item>(entt::entity(inventoryComp.quickSlots[itemId]));

			item.isEquiped = false;

			inventoryComp.items.push_back(inventoryComp.quickSlots[itemId]);
			inventoryComp.quickSlots.erase(inventoryComp.quickSlots.begin() + itemId, inventoryComp.quickSlots.begin() + itemId + 1);

			if (itemId + 1 < config.quickSlots.x * config.quickSlots.y)
			{
				inventory->get<tgui::Panel>(parentName)->get<tgui::Button>(name)->getRenderer()->setTexture({});
			}
		}
		else if (parentName == "ringEquiped")
		{
			if (itemId >= inventoryComp.ringSlots.size()) return;
			Item& item = reg.get<Item>(entt::entity(inventoryComp.ringSlots[itemId]));

			item.isEquiped = false;

			inventoryComp.items.push_back(inventoryComp.ringSlots[itemId]);
			inventoryComp.ringSlots.erase(inventoryComp.ringSlots.begin() + itemId, inventoryComp.ringSlots.begin() + itemId + 1);

			if (itemId + 1 < config.ringSlots.x * config.ringSlots.y)
			{
				inventory->get<tgui::Panel>(parentName)->get<tgui::Button>(name)->getRenderer()->setTexture({});
			}
		}

		break;
	}
}

void InventorySystem::removeItem(entt::registry& reg, tgui::Panel::Ptr inventory, tgui::Button::Ptr slot)
{
	inventory->get<tgui::Panel>("itemActions")->setVisible(false);

	uint32_t itemId = std::stoi(std::string(slot->getWidgetName()));

	std::stringstream ss;
	std::string name;
	ss << itemId + 1;
	ss >> name;

	std::string parentName = std::string(slot->getParent()->getWidgetName());
	slot->getRenderer()->setTexture({});

	auto veiw = reg.view<Inventory, PlayerInput>();
	for (auto entity : veiw)
	{
		Inventory& inventoryComp = reg.get<Inventory>(entity);
		if (parentName == "miniInventory")
		{
			if (itemId >= inventoryComp.items.size()) return;
			reg.destroy(entt::entity(inventoryComp.items[itemId]));

			inventoryComp.items.erase(inventoryComp.items.begin() + itemId, inventoryComp.items.begin() + itemId + 1);

			if (itemId + 1 < config.inventorySlots.x * config.inventorySlots.y)
			{
				inventory->get<tgui::Panel>(parentName)->get<tgui::Button>(name)->getRenderer()->setTexture({});
			}
		}
		else if (parentName == "quickAction")
		{
			if (itemId >= inventoryComp.quickSlots.size()) return;
			reg.destroy(entt::entity(inventoryComp.quickSlots[itemId]));

			inventoryComp.quickSlots.erase(inventoryComp.quickSlots.begin() + itemId, inventoryComp.quickSlots.begin() + itemId + 1);

			if (itemId + 1 < config.quickSlots.x * config.quickSlots.y)
			{
				inventory->get<tgui::Panel>(parentName)->get<tgui::Button>(name)->getRenderer()->setTexture({});
			}
		}
		else if (parentName == "ringEquiped")
		{
			if (itemId >= inventoryComp.ringSlots.size()) return;
			reg.destroy(entt::entity(inventoryComp.ringSlots[itemId]));

			inventoryComp.ringSlots.erase(inventoryComp.ringSlots.begin() + itemId, inventoryComp.ringSlots.begin() + itemId + 1);

			if (itemId + 1 < config.ringSlots.x * config.ringSlots.y)
			{
				inventory->get<tgui::Panel>(parentName)->get<tgui::Button>(name)->getRenderer()->setTexture({});
			}
		}

		break;
	}
}
