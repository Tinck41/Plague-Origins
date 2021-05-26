#include "stdafx.h"
#include "OverlaySystem.h"

void OverlaySystem::onCreate(entt::registry& reg, tgui::GuiSFML& gui)
{
	gui.get<tgui::Panel>("menuButtons")->setVisible(false);
	gui.get<tgui::Panel>("unfoldedInventory")->setVisible(false);
}

void OverlaySystem::update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt)
{
	auto view = reg.view<PlayerInput>();
	for (auto entity : view)
	{
		PlayerInput& input = reg.get<PlayerInput>(entity);

		if (input.escReleased)
		{
			if (gui.get<tgui::Panel>("unfoldedInventory")->isVisible())
			{
				tgui::Panel::Ptr inventoryPanel = gui.get<tgui::Panel>("unfoldedInventory");

				inventoryPanel->setVisible(false);
				inventoryPanel->get<tgui::Label>("itemName")->setText("");
				inventoryPanel->get<tgui::Label>("itemDescription")->setText("");
				break;
			}

			bool isVisible = gui.get<tgui::Panel>("menuButtons")->isVisible();
			gui.get<tgui::Panel>("menuButtons")->setVisible(!isVisible);

			gui.get<tgui::Panel>("statusBar")->setVisible(isVisible);
			input.canCheckForAttack = isVisible;
			input.canCheckForMovement = isVisible;
		}
	}
}

void OverlaySystem::render(entt::registry& reg, sf::RenderWindow& window, tgui::GuiSFML& gui)
{

}
