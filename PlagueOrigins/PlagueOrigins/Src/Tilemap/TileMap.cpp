#include "stdafx.h"

#include "TileMap.h"

TileMap::TileMap(std::vector<TileLayer> layers, std::vector<std::vector<MapCollider>> objects, sf::Vector2u mapSize, sf::Vector2u tileSize)
{
	this->tileLayer = layers;
	this->colliderLayer = objects;
	this->size = mapSize;
	this->tileSize = tileSize;
}

TileMap::TileMap()
{

}

TileMap::~TileMap()
{
	this->tileLayer.clear();
	this->colliderLayer.clear();
}

sf::Vector2u TileMap::getSize()
{
	return sf::Vector2u(size.x * tileSize.x, size.y * tileSize.y);
}

void TileMap::update(Player& player)
{
	ColliderComponent playerCollider = player.getCollider();

	for (auto& layer : this->colliderLayer)
	{
		for (auto& collider : layer)
		{
			collider.getCollider().checkCollision(playerCollider, 1.0f);
		}
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
	this->render(target, 0, 2);
}

void TileMap::renderOverPlayerLayers(sf::RenderTarget& target)
{
	this->render(target, 2, this->tileLayer.size());
}
