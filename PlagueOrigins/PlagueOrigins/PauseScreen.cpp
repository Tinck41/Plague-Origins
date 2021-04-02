#include "stdafx.h"
#include "PauseScreen.h"

PauseScreen::PauseScreen()
{
	this->continueButton = Button(config.width() / 2 - 90, config.height() / 2 - 25, 180, 50, 3, "Continue");
	this->mainMenuButton = Button(config.width() / 2 - 90, config.height() / 2 + 50, 180, 50, 3, "Main Menu");
	this->exitButton = Button(config.width() / 2 - 90, config.height() / 2 + 125, 180, 50, 3, "Exit");
}

PauseScreen::~PauseScreen()
{
}

void PauseScreen::update(const float& dt)
{
}

ScreenType PauseScreen::render(sf::RenderWindow& window)
{
	this->continueButton.render(window);
	this->mainMenuButton.render(window);
	this->exitButton.render(window);
	if (continueButton.state == ButtonState::RELEASED) {
		return ScreenType::GAME;
	}
	if (mainMenuButton.state == ButtonState::RELEASED) {
		return ScreenType::MAIN_MENU;
	}
	if (exitButton.state == ButtonState::RELEASED) {
		return ScreenType::EXIT;
	}
	return ScreenType::PAUSE;
}
