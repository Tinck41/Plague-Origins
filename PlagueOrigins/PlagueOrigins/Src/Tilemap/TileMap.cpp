#include "stdafx.h"

#include "TileMap.h"

TileMap::TileMap(std::vector<std::shared_ptr<TileLayer>> layers, sf::Vector2u mapSize, sf::Vector2u tileSize)
{
	tileLayers = layers;
	size = mapSize;
	this->tileSize = tileSize;
}

TileMap::~TileMap()
{
	tileLayers.clear();
}

sf::Vector2u TileMap::getSize()
{
	return sf::Vector2u(size.x * tileSize.x, size.y * tileSize.y);
}

void TileMap::update(const float& dt)
{
	for (auto& layer : tileLayers)
	{
		layer->update(dt);
	}
}

void TileMap::render(sf::RenderTarget& target, uint32_t firstLayerId, uint32_t lastLayerId)
{
	for (uint32_t i = firstLayerId; i < lastLayerId; i++)
	{
		target.draw(*tileLayers[i]);
	}
}

void TileMap::renderUnderPlayerLayers(sf::RenderTarget& target)
{
	render(target, 0, 8);
}

void TileMap::renderOverPlayerLayers(sf::RenderTarget& target)
{
	render(target, 8, tileLayers.size());
}
