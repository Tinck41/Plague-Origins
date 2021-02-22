#include "MainMenuScreen.h"

MainMenuScreen::MainMenuScreen()
{
	this->newGameButton = Button(CONFIG.WINDOW_WIDTH / 2 - 50, CONFIG.WINDOW_HEIGHT / 2 - 25, 100, 50, 3, "NEW GAME");
}

void MainMenuScreen::update(const float &dt)
{
}

ScreenType MainMenuScreen::render(sf::RenderWindow& window)
{
	this->newGameButton.render(window);
	if (this->newGameButton.state == ButtonState::RELEASED) {
		return ScreenType::GAME;
	}
	return ScreenType::MAIN_MENU;
}

MainMenuScreen::~MainMenuScreen()
{
}