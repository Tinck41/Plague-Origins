#include "stdafx.h"

#include "ScreenHandler.h"
#include "GameScreen.h"
#include "MainMenuScreen.h"
#include "PauseScreen.h"

ScreenHandler::ScreenHandler(ScreenType initialScreenType)
{
	show(initialScreenType);
}

void ScreenHandler::show(ScreenType screenType)
{
	switch (screenType) {
	case ScreenType::GAME:
		this->screen = new GameScreen();
		this->currentScreenType = ScreenType::GAME;
		break;
	case ScreenType::MAIN_MENU:
		this->screen = new MainMenuScreen();
		this->currentScreenType = ScreenType::MAIN_MENU;
		break;
	case ScreenType::LOADING:
		this->currentScreenType = ScreenType::LOADING;
		break;
	case ScreenType::EXIT:
		this->currentScreenType = ScreenType::EXIT;
		break;
	case ScreenType::PAUSE:
		this->screen = new PauseScreen();
		this->currentScreenType = ScreenType::PAUSE;
		break;
	default:
		break;
	}
}

void ScreenHandler::update(const float& dt)
{
	this->screen->update(dt);
}

void ScreenHandler::render(sf::RenderWindow& window)
{
	this->nextScreenType = this->screen->render(window);
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