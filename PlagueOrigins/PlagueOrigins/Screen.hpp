#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

class Screen
{
public:
	void update();
	virtual void render(sf::RenderWindow&);
};

