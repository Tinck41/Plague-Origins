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
	xmlTileMap.LoadFile(path);
	if (xmlTileMap.Error())
	{
		return false;
	}

	parseTileMap();

	return true;
}

void TilemapParser::parseTileMap()
{
	// Taking the root element with all info about map
	tinyxml2::XMLElement* root = xmlTileMap.RootElement();

	root->QueryUnsignedAttribute("height", &mapSize.y);
	root->QueryUnsignedAttribute("width", &mapSize.x);
	root->QueryUnsignedAttribute("tilewidth", &tileSize.x);
	root->QueryUnsignedAttribute("tileheight", &tileSize.y);

	// Reading tilesets info
	for (tinyxml2::XMLElement* e = root->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
	{
		if (static_cast<std::string>(e->Value()) == "tileset")
		{
			parseTileSet(e);
		}
	}

	// Reading layers data (array of tileId)
	for (tinyxml2::XMLElement* e = root->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
	{
		if (static_cast<std::string>(e->Value()) == "layer")
		{
			parseTileLayer(e);
		}
	}

	// Reading objects data (collision)
	for (tinyxml2::XMLElement* e = root->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
	{
		if (static_cast<std::string>(e->Value()) == "objectgroup")
		{
			//parseObjects(e);
		}
	}

	this->tileMap = TileMap(tileLayers, mapSize, tileSize);
}

void TilemapParser::parseTileSet(tinyxml2::XMLElement* xmlElement)
{
	TilesetParameters tilesetInfo;

	xmlElement->QueryUnsignedAttribute("firstgid", &tilesetInfo.firstId);
	xmlElement->QueryUnsignedAttribute("tilecount", &tilesetInfo.tileCount);
	tilesetInfo.lastId = tilesetInfo.firstId + tilesetInfo.tileCount - 2;

	tinyxml2::XMLElement* image = xmlElement->FirstChildElement();
	const char* source;
	image->QueryStringAttribute("source", &source);
	const char* subSource = source + 2;

	sf::Texture tileset;
	tileset.loadFromFile("./Assets" + static_cast<std::string>(subSource));

	for (tinyxml2::XMLElement* tile = xmlElement->FirstChildElement(); tile != nullptr; tile = tile->NextSiblingElement())
	{
		if (static_cast<std::string>(tile->Value()) == "tile")
		{
			uint32_t tileId;
			std::vector<uint32_t> tilesId;
			tile->QueryUnsignedAttribute("id", &tileId);

			float duration;
			for (tinyxml2::XMLElement* animation = tile->FirstChildElement(); animation != nullptr; animation = animation->NextSiblingElement())
			{
				if (static_cast<std::string>(animation->Value()) == "animation")
				{
					for (tinyxml2::XMLElement* frame = animation->FirstChildElement(); frame != nullptr; frame = frame->NextSiblingElement())
					{
						uint32_t id;
						frame->QueryUnsignedAttribute("tileid", &id);
						frame->QueryFloatAttribute("duration", &duration);
						tilesId.push_back(id);
					}
				}
			}

			tilesetInfo.animatedTiles.push_back(Tile(tileId, tilesId, true, duration));
		}
	}

	tilesets.push_back(tileset);
	tilesetsInfo.push_back(tilesetInfo);
}

void TilemapParser::parseTileLayer(tinyxml2::XMLElement* xmlElement)
{
	const char* layerName = "";

	tinyxml2::XMLElement* data = xmlElement->FirstChildElement();

	xmlElement->QueryStringAttribute("name", &layerName);

	std::string matrix(data->GetText());
	std::istringstream iss(matrix);
	std::string id;

	std::vector<Tile> _layer;
	unsigned tilesetId = 0;
	bool tilesetNotChoosen = true;

	for (size_t row = 0; row < mapSize.x; row++)
	{
		for (size_t column = 0; column < mapSize.y; column++)
		{
			// Get the current tile number
			uint32_t tileId = 0;
			std::getline(iss, id, ',');
			std::stringstream converter(id);
			converter >> tileId;
			if (tileId != 0)
			{
				tileId--;

				if (tilesetNotChoosen)
					for (size_t i = 0; i < tilesetsInfo.size(); i++)
					{
						if (tileId >= tilesetsInfo[i].firstId && tileId <= tilesetsInfo[i].lastId)
						{
							tilesetId = i;
							tilesetNotChoosen = false;
						}
					}

				tileId = tileId + tilesetsInfo[tilesetId].tileCount - tilesetsInfo[tilesetId].lastId - 1;
			}

			bool isAnimated = false;
			for (uint32_t i = 0; i < tilesetsInfo[tilesetId].animatedTiles.size(); i++)
			{
				if (tileId == tilesetsInfo[tilesetId].animatedTiles[i].getTileId())
				{
					_layer.push_back(tilesetsInfo[tilesetId].animatedTiles[i]);
					isAnimated = true;
					break;
				}
			}

			if (!isAnimated)
			{
				_layer.push_back(Tile(tileId, std::vector<uint32_t>(), false));
			}
		}
	}

	if (!tilesets.empty())
	{
		TileLayer layer(layerName, _layer, mapSize, tileSize, tilesets[tilesetId]);
		tileLayers.push_back(layer);
	}
	else
	{
		std::cout << "ERROR: trying to push layer with empty tileset" << "\n";
	}
}

void TilemapParser::parseObjects(tinyxml2::XMLElement* xmlElement)
{
	//std::vector<MapCollider> objects;

	//for (tinyxml2::XMLElement* e = xmlElement->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
	//{
	//	sf::Vector2f objPosition;
	//	sf::Vector2f objSize;

	//	e->QueryFloatAttribute("x", &objPosition.x);
	//	e->QueryFloatAttribute("y", &objPosition.y);

	//	e->QueryFloatAttribute("width", &objSize.x);
	//	e->QueryFloatAttribute("height", &objSize.y);

	//	objects.push_back(MapCollider(objPosition, objSize));
	//}

	//colliderLayer.push_back(objects);
}



