#include "stdafx.h"
#include "OverlaySystem.h"

void OverlaySystem::onCreate(entt::registry& reg, tgui::GuiSFML& gui)
{
	gui.get<tgui::Panel>("menuButtons")->setVisible(false);
	gui.get<tgui::Panel>("unfoldedInventory")->setVisible(false);
	gui.get<tgui::Panel>("settingsPanel")->setVisible(false);

	auto inventoryButton	= gui.get<tgui::Panel>("menuButtons")->get<tgui::Button>("inventoryButton");
	auto settginButton		= gui.get<tgui::Panel>("menuButtons")->get<tgui::Button>("settingsButton");
	auto mainMenuButton		= gui.get<tgui::Panel>("settingsPanel")->get<tgui::Button>("mainMenuButton");
	auto exitButton			= gui.get<tgui::Panel>("settingsPanel")->get<tgui::Button>("exitGameButton");

	inventoryButton->onMouseRelease(&OverlaySystem::onInventoryButtonClick, this, std::ref(reg), std::ref(gui));
	settginButton->onMouseRelease(&OverlaySystem::onSettingsButtonClick, this, std::ref(reg), std::ref(gui));
	mainMenuButton->onMouseRelease(&OverlaySystem::onMainMenuButtonClick, this, std::ref(reg), std::ref(gui));
	exitButton->onMouseRelease(&OverlaySystem::onExitButtonClick, this, std::ref(reg), std::ref(gui));
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

			if (gui.get<tgui::Panel>("settingsPanel")->isVisible())
			{
				tgui::Panel::Ptr settingsPanel = gui.get<tgui::Panel>("settingsPanel");

				settingsPanel->setVisible(false);
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

void OverlaySystem::onInventoryButtonClick(entt::registry& reg, tgui::GuiSFML& gui)
{
	if (gui.get<tgui::Panel>("settingsPanel")->isVisible())
	{
		tgui::Panel::Ptr settingsPanel = gui.get<tgui::Panel>("settingsPanel");

		settingsPanel->setVisible(false);
	}

	bool isVisable = gui.get<tgui::Panel>("unfoldedInventory")->isVisible();

	gui.get<tgui::Panel>("unfoldedInventory")->setVisible(!isVisable);

	gui.get<tgui::Label>("itemName")->setText("");
	gui.get<tgui::Label>("itemDescription")->setText("");

	gui.get<tgui::Panel>("itemActions")->setVisible(false);
}

void OverlaySystem::onSettingsButtonClick(entt::registry& reg, tgui::GuiSFML& gui)
{
	if (gui.get<tgui::Panel>("unfoldedInventory")->isVisible())
	{
		tgui::Panel::Ptr inventoryPanel = gui.get<tgui::Panel>("unfoldedInventory");

		inventoryPanel->setVisible(false);
		inventoryPanel->get<tgui::Label>("itemName")->setText("");
		inventoryPanel->get<tgui::Label>("itemDescription")->setText("");
	}

	bool isVisible = gui.get<tgui::Panel>("settingsPanel")->isVisible();
	gui.get<tgui::Panel>("settingsPanel")->setVisible(!isVisible);
}

void OverlaySystem::onExitButtonClick(entt::registry& reg, tgui::GuiSFML& gui)
{
	auto view = reg.view<CurrentScreen>();
	for (auto entity : view)
	{
		CurrentScreen& currentScreen = reg.get<CurrentScreen>(entity);

		currentScreen.type = ScreenType::EXIT;
	}
}

void OverlaySystem::onMainMenuButtonClick(entt::registry& reg, tgui::GuiSFML& gui)
{
	// Dangerous shit...
	//auto view = reg.view<CurrentScreen>();
	//for (auto entity : view)
	//{
	//	CurrentScreen& currentScreen = reg.get<CurrentScreen>(entity);

	//	currentScreen.type = ScreenType::MAIN_MENU;
	//}
}
