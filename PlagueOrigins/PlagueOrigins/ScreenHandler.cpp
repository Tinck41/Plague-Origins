#include "stdafx.h"

#include "ScreenHandler.h"
#include "GameScreen.h"
#include "MainMenuScreen.h"


ScreenHandler::ScreenHandler()
{
	initVariables();
	showGameScreen();
}

ScreenHandler::~ScreenHandler()
{
}

void ScreenHandler::initVariables()
{
	
}

void ScreenHandler::showMainMenuScreen()
{
	delete this->currentScreen;
	this->currentScreen = new MainMenuScreen();
}

void ScreenHandler::showLoadingScreen()
{
}

void ScreenHandler::showGameScreen()
{
	delete this->currentScreen;
	this->currentScreen = new GameScreen();
}

void ScreenHandler::render(sf::RenderWindow& window)
{
	this->currentScreen->render(window);
}

void ScreenHandler::update(const float& dt)
{
	this->currentScreen->update(dt);
	//std::cout << "Screen handler update invoked" << std::endl;
}
