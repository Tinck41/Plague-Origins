#include "stdafx.h"
#include "TileMap.h"

TileMap::TileMap()
{

}

TileMap::TileMap(std::vector<TileLayer> layers, sf::Vector2u size)
{
	this->layers = layers;
	this->size = size;
}

TileMap::~TileMap()
{
	this->layers.clear();
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

void TileMap::render(sf::RenderTarget& target)
{
	// Draw all vertex arrays
	for (auto& layer : this->layers)
	{
		target.draw(layer);
	}
}

void TileMap::renderFirstLayer(sf::RenderTarget& target)
{
	target.draw(this->layers[0]);
}

void TileMap::renderSecondLayer(sf::RenderTarget& target)
{
	for (int i = 1; i < this->layers.size(); i++)
	{
		target.draw(layers[i]);
	}
}

void TileMap::loadLayers()
{
	// Load all layers to the vertex arrays
	for (auto& layer : this->layers)
	{
		layer.load();
	}
}

ColliderComponent TileMap::getCollider(sf::RectangleShape& rect)
{
	return ColliderComponent(rect);
}
