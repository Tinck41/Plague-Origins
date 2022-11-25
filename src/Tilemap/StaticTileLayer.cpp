#include "stdafx.h"
#include "StaticTileLayer.h"

StaticTileLayer::StaticTileLayer(
	std::string name, std::vector<uint16_t> tiles,
	sf::Vector2u size, sf::Vector2u tileSize, std::shared_ptr<sf::Texture> tileset
)
	: TileLayer(name, size, tileSize, tileset)
{
	this->tiles = tiles;

	loadTiles();
}

StaticTileLayer::~StaticTileLayer()
{
	std::cout << "deleting tile layer: " << name << "\n";
	tiles.clear();
}

void StaticTileLayer::loadTiles()
{
	for (size_t i = 0; i < size.x; i++)
	{
		for (size_t j = 0; j < size.y; j++)
		{
			uint16_t tileNumber = tiles[i + j * size.x];

			if (tileNumber == 0) continue;

			drawTile(tileNumber, i, j);
		}
	}
}
