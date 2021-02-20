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

void TileMap::update()
{

}

void TileMap::render(sf::RenderTarget& target)
{
	// Draw all vertex arrays
	for (auto& layer : this->layers)
	{
		target.draw(layer);
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
