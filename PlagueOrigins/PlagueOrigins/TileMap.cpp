#include "stdafx.h"

#include "TileMap.h"

TileMap::TileMap(std::vector<TileLayer> layers, sf::Vector2u size, std::vector<std::vector<ColliderLayer>> objects)
{
	this->layers = layers;
	this->size = size;
	this->objects = objects;
}

TileMap::TileMap()
{

}

TileMap::~TileMap()
{
	this->layers.clear();
	this->objects.clear();
}

void TileMap::update(Player& player)
{
	ColliderComponent playerCollider = player.getCollider();

	for (auto& objectsLayer : objects)
	{
		for (auto& object : objectsLayer)
		{
			object.getCollider().checkCollision(playerCollider, 1.0f);
		}
	}
}

void TileMap::render(sf::RenderTarget& target, unsigned firstLayerId, unsigned lastLayerId)
{
	for (int i = firstLayerId; i < lastLayerId; i++)
	{
		target.draw(this->layers[i]);
	}
}

void TileMap::renderUnderPlayerLayers(sf::RenderTarget& target)
{
	this->render(target, 0, 2);
}

void TileMap::renderOverPlayerLayers(sf::RenderTarget& target)
{
	this->render(target, 2, this->layers.size());
}
