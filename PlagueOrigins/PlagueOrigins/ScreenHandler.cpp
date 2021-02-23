#include "stdafx.h"

#include "ScreenHandler.h"
#include "GameScreen.h"
#include "MainMenuScreen.h"
#include "PauseScreen.h"

ScreenHandler::ScreenHandler(ScreenType initialScreenType)
{
	initScreens();
	show(initialScreenType);
}

void ScreenHandler::initScreens()
{
	this->screens = std::map<ScreenType, Screen*>
	{
		{ GameScreen::screenType, new GameScreen() },
		{ MainMenuScreen::screenType, new MainMenuScreen() },
		{ PauseScreen::screenType, new PauseScreen() }
	};
}

void ScreenHandler::show(ScreenType screenType)
{
	this->currentScreenType = screenType;
	this->currentScreen = this->screens[screenType];
}

void ScreenHandler::update(const float& dt)
{
	if (!currentScreen) return;
	this->currentScreen->update(dt);
}

void ScreenHandler::render(sf::RenderWindow& window)
{
	if (currentScreenType == ScreenType::EXIT) 
	{
		window.close();
		return;
	}
	this->nextScreenType = this->currentScreen->render(window);
	if (nextScreenType != currentScreenType) 
	{
		show(nextScreenType);
	}
}

ScreenHandler::~ScreenHandler()
{
}