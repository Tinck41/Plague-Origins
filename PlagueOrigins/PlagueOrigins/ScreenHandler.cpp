#include "stdafx.h"

#include "ScreenHandler.h"
#include "GameScreen.h"
#include "MainMenuScreen.h"

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
		this->screen = NULL;
		this->currentScreenType = ScreenType::LOADING;
		break;
	default:
		break;
	}
}

void ScreenHandler::render(sf::RenderWindow& window)
{
	this->nextScreenType = this->screen->render(window);
	if (nextScreenType != currentScreenType) 
	{
		show(nextScreenType);
	}
}

void ScreenHandler::update(const float& dt)
{
	this->screen->update(dt);
}

ScreenHandler::~ScreenHandler()
{
}