#pragma once

#include "stdafx.h"

#include "Screen.h"
#include "GameScreen.h"
#include "MainMenuScreen.h"

class ScreenHandler
{
private:
	Screen* screen;
	ScreenType currentScreenType;
	ScreenType nextScreenType;
public:
	ScreenHandler(ScreenType initialScreenType);
	~ScreenHandler();

	void show(ScreenType);
	void render(sf::RenderWindow&);
	void update(const float&);
};

