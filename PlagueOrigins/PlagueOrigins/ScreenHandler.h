#pragma once
#include "Screen.h"
#include "GameScreen.h"
#include "MainMenuScreen.h"
#include "stdafx.h"

class ScreenHandler
{
public:
	Screen* currentScreen;

	ScreenHandler();
	~ScreenHandler();

	void showMainMenuScreen();
	void showLoadingScreen();
	void initVariables();
	void showGameScreen();
	void render(sf::RenderWindow& window);
	void update(const float& dt);
};

