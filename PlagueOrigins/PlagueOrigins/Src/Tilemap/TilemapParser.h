#pragma once

#include "TileMap.h"
#include "tinyxml2.h"

class TilemapParser
{
private:
	tinyxml2::XMLDocument xmlTileMap;

	TileMap tileMap;

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