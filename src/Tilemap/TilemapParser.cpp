#include "stdafx.h"

#include "TilemapParser.h"


TilemapParser::TilemapParser()
{

}

TilemapParser::~TilemapParser()
{
	screen = nullptr;
	registry = nullptr;

	tilesetsInfo.clear();
	tilesets.clear();
	tileLayers.clear();
}

bool TilemapParser::loadTileMap(const char* path, entt::registry* reg, Screen* screen)
{
	registry = reg;
	this->screen = screen;

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
	parseTileMapObjects();
	parseSoundSources();
	parseBossFightTriggers();

	tileMap = TileMap(tileLayers, mapSize, tileSize);
}

void TilemapParser::parseTileSet()
{
	size_t tilesetsCount = jsonReader["tilesets"].size();
	for (size_t i = 0; i < tilesetsCount; i++)
	{
		TilesetParameters tilesetInfo;

		tilesetInfo.id			= jsonReader["tilesets"][i]["properties"][0]["value"];
		tilesetInfo.firstId		= jsonReader["tilesets"][i]["firstgid"];
		tilesetInfo.tileCount	= jsonReader["tilesets"][i]["tilecount"];
		tilesetInfo.lastId		= tilesetInfo.firstId + tilesetInfo.tileCount - 2;

		std::string source = jsonReader["tilesets"][i]["image"];
		source.erase(source.begin(), source.begin() + 2);
		
		std::shared_ptr<sf::Texture> tileset = std::make_shared<sf::Texture>();
		tileset->loadFromFile("./Assets" + source);

		if (jsonReader["tilesets"][i].contains("tiles"))
		{
			size_t tilesCount = jsonReader["tilesets"][i]["tiles"].size();
			for (size_t j = 0; j < tilesCount; j++)
			{
				uint16_t				tileId;
				std::vector<uint16_t>	tilesId;
				float duration;

				tileId = jsonReader["tilesets"][i]["tiles"][j]["id"];

				size_t framesCount = jsonReader["tilesets"][i]["tiles"][j]["animation"].size();
				for (size_t k = 0; k < framesCount; k++)
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
	size_t layersCount = jsonReader["layers"].size();
	for (size_t i = 0; i < layersCount; i++)
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

	size_t tilesCount = node.size();
	for (size_t j = 0; j < tilesCount; j++)
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

	size_t tilesCount = node.size();
	for (size_t j = 0; j < tilesCount; j++)
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

	TILEMAP_PARSER_ERROR("could not load the animated tile with id: " + std::to_string(tileId));

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

	TILEMAP_PARSER_ERROR("could not load the tileset with id: " + std::to_string(tileSetId));

	return tilesetsInfo[0];
}

void TilemapParser::parseTileMapObjects()
{
	size_t layersCount = jsonReader["layers"].size();
	for (size_t i = 0; i < layersCount; i++)
	{
		if (jsonReader["layers"][i]["type"] == "objectgroup" && jsonReader["layers"][i]["properties"][0]["value"] == "collision")
		{
			size_t objectsCount = jsonReader["layers"][i]["objects"].size();
			for (size_t j = 0; j < objectsCount; j++)
			{
				float width		= jsonReader["layers"][i]["objects"][j]["width"];
				float height	= jsonReader["layers"][i]["objects"][j]["height"];

				float x = jsonReader["layers"][i]["objects"][j]["x"];
				float y = jsonReader["layers"][i]["objects"][j]["y"];
				
				Entity object = Entity(registry->create(), screen);
				PhysicsWorld::createRectangleBody(sf::Vector2f(x, y), sf::Vector2f(width, height), false, object, OBSTACLE, PLAYER | ENEMY_NPC);
			}
		}
	}
}

void TilemapParser::parseSoundSources()
{
	size_t layersCount = jsonReader["layers"].size();
	for (size_t i = 0; i < layersCount; i++)
	{
		if (jsonReader["layers"][i]["type"] == "objectgroup" && jsonReader["layers"][i]["properties"][0]["value"] == "sound")
		{
			size_t objectsCount = jsonReader["layers"][i]["objects"].size();
			for (size_t j = 0; j < objectsCount; j++)
			{
				Entity sound = Entity(registry->create(), screen);
				sound.AddComponent<AmbienceAudioSource>();

				AmbienceAudioSource& soundSource = sound.GetComponent<AmbienceAudioSource>();
				soundSource.playWindSound = false;
				soundSource.loopWindSound = false;
				
				float x = jsonReader["layers"][i]["objects"][j]["x"];
				float y = jsonReader["layers"][i]["objects"][j]["y"];

				soundSource.torchSoundPosition = sf::Vector3f(x, 0.f, y);
			}
		}
	}
}

void TilemapParser::parseBossFightTriggers()
{
	size_t layersCount = jsonReader["layers"].size();
	for (size_t i = 0; i < layersCount; i++)
	{
		if (jsonReader["layers"][i]["type"] == "objectgroup" && jsonReader["layers"][i]["properties"][0]["value"] == "bossFightTrigger")
		{
			size_t objectsCount = jsonReader["layers"][i]["objects"].size();
			for (size_t j = 0; j < objectsCount; j++)
			{
				Entity bossFightTrigger = Entity(registry->create(), screen);

				float x			= jsonReader["layers"][i]["objects"][j]["x"];
				float y			= jsonReader["layers"][i]["objects"][j]["y"];

				float width		= jsonReader["layers"][i]["objects"][j]["width"];
				float height	= jsonReader["layers"][i]["objects"][j]["height"];

				bossFightTrigger.AddComponent<BossFightArena>();
				bossFightTrigger.AddComponent<RigidBody>(sf::Vector2f(width, height), sf::Vector2f(x, y), false, bossFightTrigger, BOSS_FIGHT_TRIGGER, PLAYER)
					.body->GetFixtureList()->SetSensor(true);

				uint8_t propertiesCount = 4;
				size_t	doorCount		= jsonReader["layers"][i]["objects"][j]["properties"].size() / propertiesCount;
				for (size_t k = 0; k < doorCount; k++)
				{
					Entity door = Entity(registry->create(), screen);
					uint16_t param = k * propertiesCount;

					float doorHeight	= jsonReader["layers"][i]["objects"][j]["properties"][0 + param]["value"];
					float doorWidth		= jsonReader["layers"][i]["objects"][j]["properties"][1 + param]["value"];

					float doorX			= jsonReader["layers"][i]["objects"][j]["properties"][2 + param]["value"];
					float doorY			= jsonReader["layers"][i]["objects"][j]["properties"][3 + param]["value"];

					door.AddComponent<RigidBody>(sf::Vector2f(doorWidth, doorHeight), sf::Vector2f(doorX, doorY), false, door, OBSTACLE, PLAYER | ENEMY_NPC)
						.body->GetFixtureList()->SetSensor(true);

					bossFightTrigger.GetComponent<BossFightArena>().doors.push_back(door);
				}
			}
		}
	}
}