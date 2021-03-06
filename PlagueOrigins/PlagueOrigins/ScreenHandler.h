#pragma once

#include "Screen.h"
#include "GameScreen.h"
#include "MainMenuScreen.h"
#include "PauseScreen.h"

class ScreenHandler
{
private:
	Screen* currentScreen;
	ScreenType currentScreenType;
	ScreenType nextScreenType;

	std::map<ScreenType, Screen*> screens;
	void initScreens();
public:
	ScreenHandler(ScreenType initialScreenType);
	~ScreenHandler();

	void show(ScreenType);
	void render(sf::RenderWindow&);
	void update(const float&);
};

