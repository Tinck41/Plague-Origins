#pragma once

#include "SFML/Graphics.hpp"

struct Icon
{
	Icon(std::string path)
	{
		sf::Texture texture;
		texture.loadFromFile(path);

		image = tgui::Texture(texture);
	}

	tgui::Texture image;
};
