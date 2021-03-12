#include "stdafx.h"

#include "TileMap.h"

TileMap::TileMap(std::vector<TileLayer> layers, sf::Vector2u size, std::vector<std::vector<sf::RectangleShape>> objects)
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
	for (auto object : this->objects)
	{
		for (auto rect : object)
		{
			this->getCollider(rect).checkCollision(player.getCollider(), 1.0f);
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

ColliderComponent TileMap::getCollider(sf::RectangleShape& rect)
{
	return ColliderComponent(rect);
}
