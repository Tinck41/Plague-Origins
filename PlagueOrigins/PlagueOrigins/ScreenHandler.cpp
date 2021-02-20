#include "ScreenHandler.hpp"
#include "MainMenuScreen.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

ScreenHandler::ScreenHandler()
{
	this->currentScreen = new MainMenuScreen();
}

ScreenHandler::~ScreenHandler()
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
}

void ScreenHandler::render(sf::RenderWindow& window)
{
	this->currentScreen->render(window);
}

void ScreenHandler::update()
{
}
