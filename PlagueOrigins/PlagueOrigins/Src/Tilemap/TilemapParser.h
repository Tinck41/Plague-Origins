#pragma once

#include "TileMap.h"
#include "StaticTileLayer.h"
#include "AnimatedTileLayer.h"
#include "Src/Utility/json.hpp"
#include "Src/Screen/Entity.h"

#define TILEMAP_PARSER_ERROR(msg) std::cout << "Tilemap parser ERROR: " << msg << "\n"

struct TilesetParameters
{
	uint8_t		id;
	uint16_t	firstId;
	uint16_t	lastId;
	uint16_t	tileCount;
	std::vector<AnimatedTile> animatedTiles;
};

class TilemapParser
{
private:
	nlohmann::json jsonReader;

	TileMap tileMap;

	sf::Vector2u mapSize;
	sf::Vector2u tileSize;

	std::vector<TilesetParameters> tilesetsInfo;
	std::vector<std::shared_ptr<sf::Texture>> tilesets;
	//std::vector<std::vector<MapCollider>> collidersLayer;
	std::vector<std::shared_ptr<TileLayer>> tileLayers;

	void parseTileMap();
	void parseTileSet();
	void parseTileLayer();
	void parseTileMapObjects(entt::registry reg);

	void parseAnimatedTiles(std::string layerName, TilesetParameters tileset, nlohmann::json node);
	void parseStaticTiles(std::string layerName, TilesetParameters tileset, nlohmann::json node);

	TilesetParameters chooseTileSet(uint8_t tileSetId);

	AnimatedTile chooseAnimatedTile(TilesetParameters tilesetInfo, uint16_t tileId, sf::Vector2u tilePos);
public:
	TilemapParser();
	~TilemapParser();

	bool loadTileMap(const char* path);

	TileMap getTileMap() { return tileMap; }
};