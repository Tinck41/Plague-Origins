#pragma once

#include "TileMap.h"
#include "TileLayer.h"
#include "tinyxml2.h"

class TileMapLoader
{
private:
	// Variables
	// XmlReader
	tinyxml2::XMLDocument xmlTileMap;

	TileMap tileMap;

	sf::Vector2u mapSize;
	sf::Vector2u layerSize;
	sf::Vector2u tileSize;

	// Tileset additional info
	std::vector<unsigned> tilesetFirstId;
	std::vector<unsigned> tilesetLastId;
	std::vector<unsigned> tilesetTileCount;

	std::vector<sf::Texture> tilesets;
	std::vector<TileLayer> layers;
	std::vector<std::vector<sf::RectangleShape>> objects;

	// Functions
	void parseTileSet(tinyxml2::XMLElement* xmlElement);
	void parseTileLayer(tinyxml2::XMLElement* xmlElement);
	void parseObjects(tinyxml2::XMLElement* xmlElement);
public:
	// Constructor/Destructor
	TileMapLoader();
	~TileMapLoader();

	// Functions
	bool load(const char* path);
	TileMap parseTileMap();
};

