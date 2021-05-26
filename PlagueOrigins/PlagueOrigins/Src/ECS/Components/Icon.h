#pragma once

#include "SFML/Graphics.hpp"

struct Icon
{
	Icon(sf::Image image)
	{
		this->image = image;
	}

	sf::Image image;
};
