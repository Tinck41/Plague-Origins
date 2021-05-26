#pragma once

#include "SFML/Graphics.hpp"

struct Icon
{
	Icon(std::string path)
	{
		image.loadFromFile(path);
	}

	sf::Texture image;
};
