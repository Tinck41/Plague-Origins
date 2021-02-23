#pragma once

#include "stdafx.h"

#include "Screen.h"
#include "GameScreen.h"
#include "MainMenuScreen.h"

class ScreenHandler
{
private:
	Screen* currentScreen;
	ScreenType currentScreenType;
	ScreenType nextScreenType;

	std::vector<Screen*> screens;
public:
	ScreenHandler(ScreenType initialScreenType);
	~ScreenHandler();

	void show(ScreenType);
	void render(sf::RenderWindow&);
	void update(const float&);
};

