#pragma once

#include "stdafx.h"

enum class ScreenType {
	LOADING,
	PAUSE,
	GAME,
	MAIN_MENU,
	EXIT
};

class Screen
{
public:
	virtual void update(const float& dt) = 0;
	virtual ScreenType render(sf::RenderWindow&) = 0;
};

