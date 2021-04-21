#include "stdafx.h"

#include "TileLayer.h"

TileLayer::TileLayer(const char* name, std::vector<Tile> tiles, sf::Vector2u size, sf::Vector2u tileSize, sf::Texture tileset)
{
	this->name = name;
	this->tiles = tiles;
	this->size = size;
	this->tileSize = tileSize;
	this->tileset = tileset;

	firstRender = true;

	vertices.setPrimitiveType(sf::Quads);
	vertices.resize(size.x * size.y * 4);
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
	for (uint32_t i = 0; i < size.x; ++i)
	{
		for (uint32_t j = 0; j < size.y; ++j)
		{
			Tile &tile = tiles[i + j * size.x];
			if (!firstRender && tile.Animated())
			{
				tile.update(dt);
			}

			if (firstRender && !tile.Animated())
			{
				drawTile(tile.getTileId(), i, j);
			}
			else if (!firstRender && tiles[i + j * size.x].Animated())
			{
				uint32_t id = tiles[i + j * size.x].getPlayingTileId();
				drawTile(id, i, j);
			}
		}
	}

	firstRender = false;
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

