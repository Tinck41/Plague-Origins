#include "stdafx.h"

#include "MainMenuScreen.h"

MainMenuScreen::MainMenuScreen()
{
	newGameButton = Button(CONFIG.getWidth() / 2 - 90, CONFIG.getHeight() / 2 - 25, 180, 50, 3, "New Game");
	exitGameButton = Button(CONFIG.getWidth() / 2 - 90, CONFIG.getHeight() / 2 + 50, 180, 50, 3, "Exit game");
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