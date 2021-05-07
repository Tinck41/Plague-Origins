#include "stdafx.h"

#include "TilemapParser.h"


TilemapParser::TilemapParser()
{

}

TilemapParser::~TilemapParser()
{
	tilesetsInfo.clear();
	tilesets.clear();
	tileLayers.clear();
}

bool TilemapParser::loadTileMap(const char* path)
{
	try
	{
		std::ifstream stream(path);
		jsonReader = nlohmann::json::parse(stream);
	}
	catch (nlohmann::json::parse_error& ex)
	{
		std::cerr << "parse error at byte " << ex.byte << std::endl;
		return false;
	}

	parseTileMap();
	
	return true;
}

void TilemapParser::parseTileMap()
{
	//Reading tilemap generall parameters
	mapSize.x = jsonReader["width"];
	mapSize.y = jsonReader["height"];
	tileSize.x = jsonReader["tilewidth"];
	tileSize.y = jsonReader["tileheight"];

	parseTileSet();
	parseTileLayer();
	//parseObjects();

	tileMap = TileMap(tileLayers, mapSize, tileSize);
}

void TilemapParser::parseTileSet()
{
	for (size_t i = 0; i < jsonReader["tilesets"].size(); i++)
	{
		TilesetParameters tilesetInfo;

		tilesetInfo.id			= jsonReader["tilesets"][i]["properties"][0]["value"];
		tilesetInfo.firstId		= jsonReader["tilesets"][i]["firstgid"];
		tilesetInfo.tileCount	= jsonReader["tilesets"][i]["tilecount"];
		tilesetInfo.lastId		= tilesetInfo.firstId + tilesetInfo.tileCount - 2;

		std::string source = jsonReader["tilesets"][i]["image"];
		source.erase(source.begin(), source.begin() + 2);
		
		sf::Texture tileset;
		tileset.loadFromFile("./Assets" + source);

		if (jsonReader["tilesets"][i].contains("tiles"))
		{
			for (size_t j = 0; j < jsonReader["tilesets"][i]["tiles"].size(); j++)
			{
				uint16_t				tileId;
				std::vector<uint16_t>	tilesId;
				float duration;

				tileId = jsonReader["tilesets"][i]["tiles"][j]["id"];

				for (size_t k = 0; k < jsonReader["tilesets"][i]["tiles"][j]["animation"].size(); k++)
				{
					uint16_t id	= jsonReader["tilesets"][i]["tiles"][j]["animation"][k]["tileid"];
					duration	= jsonReader["tilesets"][i]["tiles"][j]["animation"][k]["duration"];

					tilesId.emplace_back(id);
				}

				tilesetInfo.animatedTiles.emplace_back(AnimatedTile(tileId, sf::Vector2u(0, 0), tilesId, duration));
			}
		}

		tilesets.emplace_back(tileset);
		tilesetsInfo.emplace_back(tilesetInfo);
	}
}

void TilemapParser::parseTileLayer()
{
	for (size_t i = 0; i < jsonReader["layers"].size(); i++)
	{
		if (jsonReader["layers"][i]["type"] == "tilelayer")
		{
			std::string layerName	= jsonReader["layers"][i]["name"];
			bool		isAnimated	= jsonReader["layers"][i]["properties"][1]["value"];
			uint8_t		tilesetId	= jsonReader["layers"][i]["properties"][2]["value"];

			TilesetParameters tilesetInfo;
			tilesetInfo = chooseTileSet(tilesetId);

			nlohmann::json dataNode = jsonReader["layers"][i]["data"];

			if (isAnimated)
			{
				parseAnimatedTiles(layerName, tilesetInfo, dataNode);
			}
			else
			{
				parseStaticTiles(layerName, tilesetInfo, dataNode);
			}
		}
	}
}

void TilemapParser::parseAnimatedTiles(std::string layerName, TilesetParameters tileset, nlohmann::json node)
{
	std::vector<AnimatedTile> layer;

	for (size_t j = 0; j < node.size(); j++)
	{
		sf::Vector2u	tilePos = sf::Vector2u(j / mapSize.x, j % mapSize.y);
		uint16_t		tileId = node[j];

		if (tileId == 0) continue;

		tileId = tileId + tileset.tileCount - tileset.lastId - 2;
			
		AnimatedTile tile = chooseAnimatedTile(tileset, tileId, tilePos);
		layer.emplace_back(tile);
	}

	std::shared_ptr<AnimatedTileLayer> tileLayer = std::make_shared<AnimatedTileLayer>(layerName, layer, mapSize, tileSize, tilesets[tileset.id]);
	tileLayers.emplace_back(tileLayer);
}

void TilemapParser::parseStaticTiles(std::string layerName, TilesetParameters tileset, nlohmann::json node)
{
	std::vector<uint16_t> layer;

	for (size_t j = 0; j < node.size(); j++)
	{
		sf::Vector2u	tilePos = sf::Vector2u(j / mapSize.x, j % mapSize.y);
		uint16_t		tileId = node[j];

		if (tileId != 0)
		{
			tileId = tileId + tileset.tileCount - tileset.lastId - 2;
		}

		layer.emplace_back(tileId);
	}

	std::shared_ptr<StaticTileLayer> tileLayer = std::make_shared<StaticTileLayer>(layerName, layer, mapSize, tileSize, tilesets[tileset.id]);
	tileLayers.emplace_back(tileLayer);
}

AnimatedTile TilemapParser::chooseAnimatedTile(TilesetParameters tilesetInfo, uint16_t tileId, sf::Vector2u tilePos)
{
	for (size_t k = 0; k < tilesetInfo.animatedTiles.size(); k++)
	{
		if (tileId == tilesetInfo.animatedTiles[k].getId())
		{
			AnimatedTile tile = AnimatedTile(tilesetInfo.animatedTiles[k]);
			tile.changePosition(tilePos);
			return tile;
		}
	}

	ERROR("could not load the animated tile with id: " + std::to_string(tileId));

	AnimatedTile tile = AnimatedTile(0, sf::Vector2u(0, 0), std::vector<uint16_t>());
	return tile;
}

TilesetParameters TilemapParser::chooseTileSet(uint8_t tileSetId)
{
	for (size_t i = 0; i < tilesetsInfo.size(); i++)
	{
		if (tilesetsInfo[i].id == tileSetId)
		{
			return tilesetsInfo[i];
		}
	}

	ERROR("could not load the tileset with id: " + std::to_string(tileSetId));

	return tilesetsInfo[0];
}

void TilemapParser::parseObjects(entt::registry reg)
{
	for (size_t i = 0; i < jsonReader["layers"].size(); i++)
	{
		if (jsonReader["layers"][i]["type"] == "objectgroup")
		{
			for (size_t j = 0; j < jsonReader["layers"][i]["type"]["objects"].size(); j++)
			{
				float width		= jsonReader["layers"][i]["type"]["objects"][j]["width"];
				float height	= jsonReader["layers"][i]["type"]["objects"][j]["height"];

				float x = jsonReader["layers"][i]["type"]["objects"][j]["x"];
				float y = jsonReader["layers"][i]["type"]["objects"][j]["y"];
				
				/*Entity object = Entity(reg.create(), this);
				PhysicsWorld::createRectangleBody(sf::Vector2f(x, y), sf::Vector2f(width, height), false, j + 10);*/
			}
		}
	}
}