#include "stdafx.h"
#include "AnimatedTileLayer.h"

AnimatedTileLayer::AnimatedTileLayer(
	std::string name, std::vector<AnimatedTile> tiles, 
	sf::Vector2u size, sf::Vector2u tileSize, std::shared_ptr<sf::Texture> tileset
) 
	: TileLayer(name, size, tileSize, tileset)
{
	this->tiles = tiles;

	loadTiles();
}

AnimatedTileLayer::~AnimatedTileLayer()
{
	tiles.clear();
}

void AnimatedTileLayer::update(const float& dt)
{
	for (auto& tile : tiles)
	{
		tile.update(dt);

		drawTile(tile.getId(), tile.getPosition().y, tile.getPosition().x);
	}
}

void AnimatedTileLayer::loadTiles()
{
	for (auto& tile : tiles)
	{
		drawTile(tile.getId(), tile.getPosition().y, tile.getPosition().x);
	}
}
