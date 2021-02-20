#pragma once

#include "stdafx.h"

class Screen
{
public:
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderWindow&) = 0;
};

