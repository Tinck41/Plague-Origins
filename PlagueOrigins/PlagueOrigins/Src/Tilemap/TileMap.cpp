#include "stdafx.h"

#include "TileMap.h"

TileMap::TileMap(std::vector<TileLayer> layers, sf::Vector2u mapSize, sf::Vector2u tileSize)
{
	this->tileLayer = layers;
	//this->colliderLayer = objects;
	this->size = mapSize;
	this->tileSize = tileSize;
}

TileMap::TileMap()
{

}

TileMap::~TileMap()
{
	this->tileLayer.clear();
	//this->colliderLayer.clear();
}

sf::Vector2u TileMap::getSize()
{
	return sf::Vector2u(size.x * tileSize.x, size.y * tileSize.y);
}

void TileMap::update(const float& dt)
{
	for (auto& layer : tileLayer)
	{
		layer.update(dt);
	}
}

void TileMap::render(sf::RenderTarget& target, unsigned firstLayerId, unsigned lastLayerId)
{
	for (int i = firstLayerId; i < lastLayerId; i++)
	{
		target.draw(this->tileLayer[i]);
	}
}

void TileMap::renderUnderPlayerLayers(sf::RenderTarget& target)
{
	this->render(target, 0, 7);
}

void TileMap::renderOverPlayerLayers(sf::RenderTarget& target)
{
	this->render(target, 7, this->tileLayer.size());
}
