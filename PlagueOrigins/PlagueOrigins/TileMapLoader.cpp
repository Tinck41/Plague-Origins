#include "stdafx.h"

#include "TileMapLoader.h"

bool TileMapLoader::load(const char* path)
{
	xmlTileMap.LoadFile(path);
	if (xmlTileMap.Error())
	{
		return false;
	}

	parseTileMap();

	return true;
}

TileMapLoader::TileMapLoader()
{

}

TileMapLoader::~TileMapLoader()
{
	this->tilesets.clear();
	this->tilesetInfo.clear();
	this->tileLayer.clear();
	this->colliderLayers.clear();
}

void TileMapLoader::parseTileMap()
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
			parseObjects(e);
		}
	}

	this->tileMap = TileMap(tileLayer, colliderLayers, mapSize, tileSize);
}

void TileMapLoader::parseTileSet(tinyxml2::XMLElement* xmlElement)
{
	TilesetParameters tilesetInfo;

	xmlElement->QueryUnsignedAttribute("firstgid", &tilesetInfo.firstId);
	xmlElement->QueryUnsignedAttribute("tilecount", &tilesetInfo.tileCount);
	tilesetInfo.lastId = tilesetInfo.firstId + tilesetInfo.tileCount - 2;

	this->tilesetInfo.push_back(tilesetInfo);

	tinyxml2::XMLElement* image = xmlElement->FirstChildElement();
	const char* source;
	image->QueryStringAttribute("source", &source);
	const char* subSource = source + 2;
	
	sf::Texture tileset;
	tileset.loadFromFile("./Assets" + static_cast<std::string>(subSource));

	tilesets.push_back(tileset);
}

void TileMapLoader::parseTileLayer(tinyxml2::XMLElement* xmlElement)
{
	const char* layerName = "";

	tinyxml2::XMLElement* data = xmlElement->FirstChildElement();

	xmlElement->QueryStringAttribute("name", &layerName);
	xmlElement->QueryUnsignedAttribute("height", &layerSize.y);
	xmlElement->QueryUnsignedAttribute("width", &layerSize.x);

	std::string matrix(data->GetText());
	std::istringstream iss(matrix);
	std::string id;

	std::vector<unsigned> _layer;
	unsigned tilesetId = 0;
	bool tilesetNotChoosen = true;

	for (size_t row = 0; row < layerSize.x; row++)
	{
		for (size_t column = 0; column < layerSize.y; column++)
		{
			// Get the current tile number
			unsigned tileId = 0;
			std::getline(iss, id, ',');
			std::stringstream converter(id);
			converter >> tileId;
			if (tileId != 0)
			{
				tileId--;

				if (tilesetNotChoosen)
					for (size_t i = 0; i < tilesetInfo.size(); i++)
					{
						if (tileId >= tilesetInfo[i].firstId && tileId <= tilesetInfo[i].lastId)
						{
							tilesetId = i;
							tilesetNotChoosen = false;
						}
					}

				tileId = tileId + tilesetInfo[tilesetId].tileCount - tilesetInfo[tilesetId].lastId - 1;
			}
			_layer.push_back(tileId);
		}
	}

	if (!tilesets.empty())
	{
		TileLayer layer(layerName, _layer, layerSize, tileSize, tilesets[tilesetId]);
		tileLayer.push_back(layer);
	}
	else
	{
		std::cout << "ERROR: trying to push layer with empty tileset" << "\n";
	}
}

void TileMapLoader::parseObjects(tinyxml2::XMLElement* xmlElement)
{
	std::vector<ColliderComponent> objects;

	for (tinyxml2::XMLElement* e = xmlElement->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
	{
		sf::Vector2f objPosition;
		sf::Vector2f objSize;

		e->QueryFloatAttribute("x", &objPosition.x);
		e->QueryFloatAttribute("y", &objPosition.y);

		e->QueryFloatAttribute("width", &objSize.x);
		e->QueryFloatAttribute("height", &objSize.y);

		objects.push_back(PhysicsWorld::createRectangleBody(objPosition, objSize, false));
	}

	colliderLayers.push_back(objects);
}
