#pragma once

#include "TileMap.h"
#include "Src/Utility/tinyxml2.h"

struct TilesetParameters
{
	uint32_t firstId;
	uint32_t lastId;
	uint32_t tileCount;
	std::vector<Tile> animatedTiles;
};

class TilemapParser
{
private:
	tinyxml2::XMLDocument xmlTileMap;

	TileMap tileMap;

	sf::Vector2u mapSize;
	sf::Vector2u tileSize;

	std::vector<TilesetParameters> tilesetsInfo;
	std::vector<sf::Texture> tilesets;
	//std::vector<std::vector<MapCollider>> collidersLayer;
	std::vector<TileLayer> tileLayers;

	void parseTileMap();
	void parseTileSet(tinyxml2::XMLElement* xmlElement);
	void parseTileLayer(tinyxml2::XMLElement* xmlElement);
	void parseObjects(tinyxml2::XMLElement* xmlElement);
public:
	TilemapParser();
	~TilemapParser();

	bool loadTileMap(const char* path);

	TileMap getTileMap() { return tileMap; }
};