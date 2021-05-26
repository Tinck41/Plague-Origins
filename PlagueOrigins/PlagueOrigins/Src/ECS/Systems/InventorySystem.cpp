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
	auto view = reg.view<Inventory, PlayerInput>();
	for (auto entity : view)
	{
		Inventory& inventory = reg.get<Inventory>(entity);
		tgui::Panel::Ptr inventoryPanel = gui.get<tgui::Panel>("unfoldedInventory");

		if (inventoryPanel->isVisible())
		{
			tgui::Panel::Ptr miniInventory = inventoryPanel->get<tgui::Panel>("miniInventory");

			for (size_t i = 0; i < inventory.items.size(); i++)
			{
				Icon& icon = reg.get<Icon>(entt::entity(inventory.items[i]));
				Item& item = reg.get<Item>(entt::entity(inventory.items[i]));

				std::stringstream ss;
				std::string name;
				ss << i;
				ss >> name;
				tgui::Button::Ptr slot = miniInventory->get<tgui::Button>(name);

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
			
			int k = config.inventorySlots.x * i + j;
			std::stringstream ss;
			std::string name;
			ss << k;
			ss >> name;
			panel->add(slot, name);
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

			panel->add(slot, std::to_string(int(config.ringSlots.x * i + j)));
		}
	}
}

void InventorySystem::onMouseRelease(entt::registry& reg, tgui::GuiSFML& gui)
{

}
