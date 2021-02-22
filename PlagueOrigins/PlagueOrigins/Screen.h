#pragma once

#include "stdafx.h"

enum ScreenType {
	LOADING,
	GAME,
	MAIN_MENU
};

class Screen
{
public:
	virtual void update(const float& dt) = 0;
	virtual ScreenType render(sf::RenderWindow&) = 0;
};

