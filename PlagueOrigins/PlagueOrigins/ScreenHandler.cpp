#include "stdafx.h"

#include "ScreenHandler.h"
#include "GameScreen.h"
#include "MainMenuScreen.h"
#include "PauseScreen.h"

ScreenHandler::ScreenHandler(ScreenType initialScreenType)
{
	this->screens = std::vector<Screen*>
	{
		new MainMenuScreen(),
		new GameScreen(),
		new PauseScreen()
	};
	show(initialScreenType);
}

void ScreenHandler::show(ScreenType screenType)
{
	switch (screenType) {
	case ScreenType::MAIN_MENU:
		this->currentScreen = this->screens.at(0);
		this->currentScreenType = ScreenType::MAIN_MENU;
		break;
	case ScreenType::GAME:
		this->currentScreen = this->screens.at(1);
		this->currentScreenType = ScreenType::GAME;
		break;
	case ScreenType::PAUSE:
		this->currentScreen = this->screens.at(2);
		this->currentScreenType = ScreenType::PAUSE;
		break;
	case ScreenType::LOADING:
		this->currentScreenType = ScreenType::LOADING;
		break;
	case ScreenType::EXIT:
		this->currentScreenType = ScreenType::EXIT;
		break;
	default:
		break;
	}
}

void ScreenHandler::update(const float& dt)
{
	this->currentScreen->update(dt);
}

void ScreenHandler::render(sf::RenderWindow& window)
{
	this->nextScreenType = this->currentScreen->render(window);
	if (currentScreenType == ScreenType::EXIT) 
	{
		window.close();
		return;
	}
	if (nextScreenType != currentScreenType) 
	{
		show(nextScreenType);
	}
}

ScreenHandler::~ScreenHandler()
{
}