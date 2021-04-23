#pragma once

#include "TileMap.h"
#include "TileLayer.h"
#include "tinyxml2.h"

struct TilesetParameters
{
	unsigned firstId;
	unsigned lastId;
	unsigned tileCount;
};

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

	// Tilemap components
	std::vector<sf::Texture> tilesets;
	std::vector<TilesetParameters> tilesetInfo;
	std::vector<TileLayer> tileLayer;
	std::vector<std::vector<ColliderComponent>> colliderLayers;

	// Functions
	void parseTileMap();
	void parseTileSet(tinyxml2::XMLElement* xmlElement);
	void parseTileLayer(tinyxml2::XMLElement* xmlElement);
	void parseObjects(tinyxml2::XMLElement* xmlElement);
public:
	// Constructor/Destructor
	TileMapLoader();
	~TileMapLoader();

	// Getters
	TileMap getTileMap() { return tileMap; }

	// Functions
	bool load(const char* path);
};

