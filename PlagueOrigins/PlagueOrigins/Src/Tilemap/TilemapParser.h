#pragma once

#include "TileMap.h"
#include "Src/Utility/json.hpp"
#include "Src/Screen/Entity.h"

#define ERROR(msg) std::cout << "Tilemap parser ERROR: " << msg << "\n"

struct TilesetParameters
{
	uint32_t id;
	uint32_t firstId;
	uint32_t lastId;
	uint32_t tileCount;
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
	std::vector<sf::Texture> tilesets;
	//std::vector<std::vector<MapCollider>> collidersLayer;
	std::vector<TileLayer> tileLayers;

	void parseTileMap();
	void parseTileSet();
	void parseTileLayer();
	void parseObjects(entt::registry reg);

	TilesetParameters chooseTileSet(uint32_t tileSetId);
	std::shared_ptr <AnimatedTile> chooseAnimatedTile(TilesetParameters tilesetInfo, uint32_t tileId, sf::Vector2u tilePos);
public:
	TilemapParser();
	~TilemapParser();

	bool loadTileMap(const char* path);

	TileMap getTileMap() { return tileMap; }
};