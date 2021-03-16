#include "stdafx.h"

#include "TileMapLoader.h"

bool TileMapLoader::load(const char* path)
{
	this->xmlTileMap.LoadFile(path);
	if (this->xmlTileMap.Error())
	{
		return false;
	}

	this->parseTileMap();

	return true;
}

TileMapLoader::TileMapLoader()
{

}

TileMapLoader::~TileMapLoader()
{
	this->tilesets.clear();
	this->tilesetInfo.clear();
	this->layers.clear();
	this->objects.clear();
}

void TileMapLoader::parseTileMap()
{
	// Taking the root element with all info about map
	tinyxml2::XMLElement* root = this->xmlTileMap.RootElement();

	root->QueryUnsignedAttribute("height", &this->mapSize.y);
	root->QueryUnsignedAttribute("width", &this->mapSize.x);
	root->QueryUnsignedAttribute("tilewidth", &this->tileSize.x);
	root->QueryUnsignedAttribute("tileheight", &this->tileSize.y);

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

	this->tileMap = TileMap(this->layers, this->mapSize, this->objects);
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

	this->tilesets.push_back(tileset);
}

void TileMapLoader::parseTileLayer(tinyxml2::XMLElement* xmlElement)
{
	const char* layerName = "";

	tinyxml2::XMLElement* data = xmlElement->FirstChildElement();

	xmlElement->QueryStringAttribute("name", &layerName);
	xmlElement->QueryUnsignedAttribute("height", &this->layerSize.y);
	xmlElement->QueryUnsignedAttribute("width", &this->layerSize.x);

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
					for (size_t i = 0; i < this->tilesetInfo.size(); i++)
					{
						if (tileId >= this->tilesetInfo[i].firstId && tileId <= this->tilesetInfo[i].lastId)
						{
							tilesetId = i;
							tilesetNotChoosen = false;
						}
					}

				tileId = tileId + this->tilesetInfo[tilesetId].tileCount - this->tilesetInfo[tilesetId].lastId - 1;
			}
			_layer.push_back(tileId);
		}
	}

	if (!this->tilesets.empty())
	{
		TileLayer layer(layerName, _layer, this->layerSize, this->tileSize, this->tilesets[tilesetId]);
		this->layers.push_back(layer);
	}
	else
	{
		std::cout << "ERROR: trying to push layer with empty tileset" << "\n";
	}
}

void TileMapLoader::parseObjects(tinyxml2::XMLElement* xmlElement)
{
	std::vector<ColliderLayer> objects;

	for (tinyxml2::XMLElement* e = xmlElement->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
	{
		sf::Vector2f objPosition;
		sf::Vector2f objSize;

		e->QueryFloatAttribute("x", &objPosition.x);
		e->QueryFloatAttribute("y", &objPosition.y);

		e->QueryFloatAttribute("width", &objSize.x);
		e->QueryFloatAttribute("height", &objSize.y);

		objects.push_back(ColliderLayer(objPosition, objSize));
	}

	this->objects.push_back(objects);
}
