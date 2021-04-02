#include "stdafx.h"
#include "MainMenuScreen.h"

MainMenuScreen::MainMenuScreen()
{
	newGameButton = Button(config.width() / 2 - 90, config.height() / 2 - 25, 180, 50, 3, "New Game");
	exitGameButton = Button(config.width() / 2 - 90, config.height() / 2 + 50, 180, 50, 3, "Exit game");
}

void MainMenuScreen::update(const float &dt)
{
}

ScreenType MainMenuScreen::render(sf::RenderWindow& window)
{
	newGameButton.render(window);
	exitGameButton.render(window);
	if (newGameButton.state == ButtonState::RELEASED) {
		return ScreenType::GAME;
	}
	if (exitGameButton.state == ButtonState::RELEASED) {
		return ScreenType::EXIT;
	}
	return ScreenType::MAIN_MENU;
}