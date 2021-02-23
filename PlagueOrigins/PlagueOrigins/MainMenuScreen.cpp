#include "MainMenuScreen.h"

MainMenuScreen::MainMenuScreen()
{
	this->newGameButton = Button(CONFIG.WINDOW_WIDTH / 2 - 90, CONFIG.WINDOW_HEIGHT / 2 - 25, 180, 50, 3, "New Game");
	this->exitGameButton = Button(CONFIG.WINDOW_WIDTH / 2 - 90, CONFIG.WINDOW_HEIGHT / 2 + 50, 180, 50, 3, "Exit game");
}

void MainMenuScreen::update(const float &dt)
{
}

ScreenType MainMenuScreen::render(sf::RenderWindow& window)
{
	this->newGameButton.render(window);
	this->exitGameButton.render(window);
	if (this->newGameButton.state == ButtonState::RELEASED) {
		return ScreenType::GAME;
	}
	if (this->exitGameButton.state == ButtonState::RELEASED) {
		return ScreenType::EXIT;
	}
	return ScreenType::MAIN_MENU;
}

MainMenuScreen::~MainMenuScreen()
{
}