#include "stdafx.h"

#include "AnimatedTile.h"

AnimatedTile::AnimatedTile(uint32_t tileId, std::vector<uint32_t> tilesId) :
	Tile(tileId)
{
	this->tilesId = tilesId;
}

AnimatedTile::~AnimatedTile()
{
	tilesId.clear();
}

void AnimatedTile::update(const float& dt)
{
	if (it == tilesId.end())
		it == tilesId.begin();

	it++;
}
