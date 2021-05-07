#pragma once

#include "TileLayer.h"

class StaticTileLayer : 
	public TileLayer
{
private:
	std::vector<uint16_t> tiles;

	void loadTiles();
public:
	StaticTileLayer(
		std::string name, std::vector<uint16_t> tiles,
		sf::Vector2u size, sf::Vector2u tileSize, sf::Texture tileset);
	~StaticTileLayer();
};
