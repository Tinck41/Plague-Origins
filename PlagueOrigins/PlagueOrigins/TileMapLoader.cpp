#include "stdafx.h"
#include "TileMapLoader.h"

bool TileMapLoader::load(const char* path)
{
	this->xmlTileMap.LoadFile(path);
	if (this->xmlTileMap.Error())
	{
		return false;
	}
	return true;
}

TileMapLoader::TileMapLoader()
{

}

TileMapLoader::~TileMapLoader()
{
	this->tilesets.clear();
	this->tilesetFirstId.clear();
	this->tilesetLastId.clear();
	this->tilesetTileCount.clear();
	this->layers.clear();
}

TileMap TileMapLoader::parseTileMap()
{
	// Taking the root element with all info about map
	tinyxml2::XMLElement* root = this->xmlTileMap.RootElement();

	root->QueryUnsignedAttribute("height", &this->mapSize.y);
	root->QueryUnsignedAttribute("width", &this->mapSize.x);
	root->QueryUnsignedAttribute("tileheight", &this->tileSize.x);
	this->tileSize.y = this->tileSize.x;

	// Reading tileset info
	for (tinyxml2::XMLElement* e = root->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
	{
		if (static_cast<std::string>(e->Value()) == "tileset")
		{
			parseTileSet(e);
		}
	}

	// Reading layer data (array of tileId)
	for (tinyxml2::XMLElement* e = root->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
	{
		if (static_cast<std::string>(e->Value()) == "layer")
		{
			parseTileLayer(e);
		}
	}

	this->tileMap.setSize(this->mapSize);
	this->tileMap.setLayers(this->layers);

	return this->tileMap;
}

void TileMapLoader::parseTileSet(tinyxml2::XMLElement* xmlElement)
{
	unsigned firstId = 0, lastId = 0, tileCount = 0;

	xmlElement->QueryUnsignedAttribute("firstgid", &firstId);
	xmlElement->QueryUnsignedAttribute("tilecount", &tileCount);
	lastId = tileCount + firstId - 2;

	this->tilesetFirstId.push_back(firstId);
	this->tilesetLastId.push_back(lastId);
	this->tilesetTileCount.push_back(tileCount);

	tinyxml2::XMLElement* image = xmlElement->FirstChildElement();
	const char* source;
	image->QueryStringAttribute("source", &source);
	const char* subSource = source + 2;
	
	sf::Texture tileset;
	tileset.loadFromFile("./Assets/" + static_cast<std::string>(subSource));

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

	std::vector<unsigned> m_layer;
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
					for (size_t i = 0; i < this->tilesetFirstId.size(); i++)
					{
						if (tileId >= this->tilesetFirstId[i] && tileId <= this->tilesetLastId[i])
						{
							tilesetId = i;
							tilesetNotChoosen = false;
						}
					}

				tileId = tileId + this->tilesetTileCount[tilesetId] - this->tilesetLastId[tilesetId] - 1;
			}
			m_layer.push_back(tileId);
		}
	}

	if (!this->tilesets.empty())
	{
		TileLayer layer(layerName, m_layer, this->layerSize, this->tileSize, this->tilesets[tilesetId]);
		this->layers.push_back(layer);
	}
	else
	{
		std::cout << "ERROR: trying to push layer with empty tileset" << "\n";
	}
}