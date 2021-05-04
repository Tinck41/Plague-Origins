#include "stdafx.h"

#include "TilemapParser.h"

TilemapParser::TilemapParser()
{

}

TilemapParser::~TilemapParser()
{
	tilesetsInfo.clear();
	tilesets.clear();
	//collidersLayer.clear();
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
	//Reading tilemap main parameters
	mapSize.x = jsonReader["width"];
	mapSize.y = jsonReader["height"];
	tileSize.x = jsonReader["tilewidth"];
	tileSize.y = jsonReader["tileheight"];

	parseTileSet();
	parseTileLayer();
	//parseObjects();

	this->tileMap = TileMap(tileLayers, mapSize, tileSize);
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
				uint32_t				tileId;
				std::vector<uint32_t>	tilesId;
				float duration;

				tileId = jsonReader["tilesets"][i]["tiles"][j]["id"];

				for (size_t k = 0; k < jsonReader["tilesets"][i]["tiles"][j]["animation"].size(); k++)
				{
					uint32_t id	= jsonReader["tilesets"][i]["tiles"][j]["animation"][k]["tileid"];
					duration	= jsonReader["tilesets"][i]["tiles"][j]["animation"][k]["duration"];

					tilesId.push_back(id);
				}

				tilesetInfo.animatedTiles.push_back(AnimatedTile(tileId, sf::Vector2u(0, 0), tilesId, duration));
			}
		}

		tilesets.push_back(tileset);
		tilesetsInfo.push_back(tilesetInfo);
	}
}

void TilemapParser::parseTileLayer()
{
	for (size_t i = 0; i < jsonReader["layers"].size(); i++)
	{
		if (jsonReader["layers"][i]["type"] == "tilelayer")
		{
			std::vector<std::shared_ptr<StaticTile>> layer;

			std::string layerName	= jsonReader["layers"][i]["name"];
			bool		isAnimated	= jsonReader["layers"][i]["properties"][0]["value"];
			uint32_t	tilesetId	= jsonReader["layers"][i]["properties"][1]["value"];

			TilesetParameters tilesetInfo;
			tilesetInfo = chooseTileSet(tilesetId);

			for (size_t j = 0; j < jsonReader["layers"][i]["data"].size(); j++)
			{
				sf::Vector2u	tilePos	= sf::Vector2u(j / mapSize.x, j % mapSize.y);
				uint32_t		tileId	= jsonReader["layers"][i]["data"][j];

				if (tileId == 0) continue;

				tileId = tileId + tilesetInfo.tileCount - tilesetInfo.lastId - 2;

				if (isAnimated)
				{
					for (size_t k = 0; k < tilesetInfo.animatedTiles.size(); k++)
					{
						if (tileId == tilesetInfo.animatedTiles[k].getId())
						{
							std::shared_ptr<AnimatedTile> tile = std::make_shared<AnimatedTile>(tilesetInfo.animatedTiles[k]);
							tile->changePosition(tilePos);
							layer.push_back(tile);
							break;
						}
					}
				}
				else
				{
					std::shared_ptr<StaticTile> tile = std::make_shared<StaticTile>(tileId, tilePos);
					layer.push_back(tile);
				}
			}

			TileLayer tileLayer(layerName, isAnimated, layer, mapSize, tileSize, tilesets[tilesetId]);
			tileLayers.emplace_back(tileLayer);
		}
	}
}

TilesetParameters TilemapParser::chooseTileSet(uint32_t tileSetId)
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