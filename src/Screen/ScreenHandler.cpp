#include "stdafx.h"

#include "ScreenHandler.h"

ScreenHandler::ScreenHandler(ScreenType initialScreenType)
{
	initScreens();
	show(initialScreenType);
}

void ScreenHandler::initScreens()
{
	screens = std::map<ScreenType, Screen*>
	{
		{ GameScreen::screenType, new GameScreen() },
		{ MainMenuScreen::screenType, new MainMenuScreen() },
	};
}

void ScreenHandler::show(ScreenType screenType)
{
	currentScreenType = screenType;
	currentScreen = screens[screenType];
}

void ScreenHandler::update(const float& dt)
{
	if (!currentScreen) return;
	currentScreen->update(dt);
}

void ScreenHandler::render(sf::RenderWindow& window)
{
	if (currentScreenType == ScreenType::EXIT) 
	{
		window.close();
		return;
	}

	nextScreenType = currentScreen->render(window);
	if (nextScreenType != currentScreenType) 
	{
		show(nextScreenType);
	}
}

ScreenHandler::~ScreenHandler()
{
	delete currentScreen;
}