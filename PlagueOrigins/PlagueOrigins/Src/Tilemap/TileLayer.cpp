#include "stdafx.h"

#include "TileLayer.h"

TileLayer::TileLayer(std::string name, bool isAnimated, std::vector<StaticTile*> tiles, sf::Vector2u size, sf::Vector2u tileSize, sf::Texture tileset)
{
	this->name = name;
	this->isAnimated = isAnimated;
	this->tiles = tiles;
	this->size = size;
	this->tileSize = tileSize;
	this->tileset = tileset;

	vertices.setPrimitiveType(sf::Quads);
	vertices.resize(size.x * size.y * 4);

	loadLayer();
}

TileLayer::~TileLayer()
{
	

	tiles.clear();
	vertices.clear();
}

void TileLayer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// apply the transform
	states.transform *= getTransform();

	// our particles don't use a texture
	states.texture = &tileset;

	// draw the vertex array
	target.draw(vertices, states);
}

void TileLayer::update(const float& dt)
{
	// update animated tiles
	if (isAnimated)
	{
		for (size_t i = 0; i < tiles.size(); ++i)
		{
			StaticTile* tile = tiles[i];

			tile->update(dt);

			drawTile(tile->getId(), tile->getPosition().y, tile->getPosition().x);
		}
	}
}

void TileLayer::drawTile(uint32_t tileNumber, uint32_t x, uint32_t y)
{
	// find its position in the tileset texture
	int tu = tileNumber % (tileset.getSize().x / tileSize.x);
	int tv = tileNumber / (tileset.getSize().x / tileSize.x);

	// get a pointer to the current tile's quad
	sf::Vertex* quad = &vertices[(x + y * size.x) * 4];

	// define its 4 corners
	quad[0].position = sf::Vector2f(x * tileSize.x, y * tileSize.y);
	quad[1].position = sf::Vector2f((x + 1) * tileSize.x, y * tileSize.y);
	quad[2].position = sf::Vector2f((x + 1) * tileSize.x, (y + 1) * tileSize.y);
	quad[3].position = sf::Vector2f(x * tileSize.x, (y + 1) * tileSize.y);

	// define its 4 texture coordinates
	quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
	quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
	quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
	quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
}

void TileLayer::loadLayer()
{
	for (size_t i = 0; i < tiles.size(); ++i)
	{
		// get the current tile number
		StaticTile* tile = tiles[i];

		if (tile->getId() == 0) continue;

		drawTile(tile->getId(), tile->getPosition().y, tile->getPosition().x);
	}
}