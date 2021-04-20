#pragma once

#include "Tile.h"

class StaticTile
	: public Tile
{
private:

public:
	StaticTile(uint32_t tileId);
	~StaticTile() {}
};