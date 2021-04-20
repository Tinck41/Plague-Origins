#include "stdafx.h"

#include "TilemapParser.h"

TilemapParser::TilemapParser()
{
}

TilemapParser::~TilemapParser()
{
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
			parseObjects(e);
		}
	}

	this->tileMap = TileMap(tileLayer, colliderLayer, mapSize, tileSize);
}

void TilemapParser::parseTileSet(tinyxml2::XMLElement* xmlElement)
{
}

void TilemapParser::parseTileLayer(tinyxml2::XMLElement* xmlElement)
{
}

void TilemapParser::parseObjects(tinyxml2::XMLElement* xmlElement)
{
}



