#pragma once

#include "stdafx.h"

#include "Screen.h"
#include "GameScreen.h"
#include "MainMenuScreen.h"

class ScreenHandler
{
public:
	Screen* currentScreen;

	GameScreen* gameScreen;
	MainMenuScreen* mainMenuScreen;

	ScreenHandler();
	~ScreenHandler();

	void showMainMenuScreen();
	void showLoadingScreen();
	void initVariables();
	void showGameScreen();
	void render(sf::RenderWindow& window);
	void update(const float& dt);
};

