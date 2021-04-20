#include "stdafx.h"

#include "TileLayer.h"

void TileLayer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// apply the transform
	states.transform *= getTransform();

	// our particles don't use a texture
	states.texture = &this->tileset;

	// draw the vertex array
	target.draw(this->vertices, states);
}

void TileLayer::load()
{
	this->vertices.setPrimitiveType(sf::Quads);
	this->vertices.resize(this->size.x * this->size.y * 4);

	for (unsigned int i = 0; i < this->size.x; ++i)
	{
		for (unsigned int j = 0; j < this->size.y; ++j)
		{
			// get the current tile number
			int tileNumber = layer[i + j * this->size.x].getTileId();

			// find its position in the tileset texture
			int tu = tileNumber % (this->tileset.getSize().x / this->tileSize.x);
			int tv = tileNumber / (this->tileset.getSize().x / this->tileSize.x);

			// get a pointer to the current tile's quad
			sf::Vertex* quad = &this->vertices[(i + j * this->size.x) * 4];

			// define its 4 corners
			quad[0].position = sf::Vector2f(i * this->tileSize.x, j * this->tileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * this->tileSize.x, j * this->tileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * this->tileSize.x, (j + 1) * this->tileSize.y);
			quad[3].position = sf::Vector2f(i * this->tileSize.x, (j + 1) * this->tileSize.y);

			// define its 4 texture coordinates
			quad[0].texCoords = sf::Vector2f(tu * this->tileSize.x, tv * this->tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * this->tileSize.x, tv * this->tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * this->tileSize.x, (tv + 1) * this->tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * this->tileSize.x, (tv + 1) * this->tileSize.y);
		}
	}
}

TileLayer::TileLayer(const char* name, std::vector<Tile> layer, sf::Vector2u size, sf::Vector2u tileSize, sf::Texture tileset)
{
	this->name = name;
	this->layer = layer;
	this->size = size;
	this->tileSize = tileSize;
	this->tileset = tileset;

	this->load();
}

TileLayer::TileLayer()
{
}

TileLayer::~TileLayer()
{
	this->layer.clear();
	this->vertices.clear();
}

void TileLayer::update()
{
}

