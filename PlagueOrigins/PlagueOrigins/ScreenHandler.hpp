#pragma once
#include "Screen.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

class ScreenHandler
{
public:
	Screen* currentScreen;

	ScreenHandler();
	~ScreenHandler();

	void showMainMenuScreen();
	void showLoadingScreen();
	void showGameScreen();
	void render(sf::RenderWindow& window);
	void update();
};

