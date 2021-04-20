#pragma once

#include "Tile.h"

class AnimatedTile
	: public Tile
{
private:
	std::vector<uint32_t> tilesId;
	std::vector<uint32_t>::iterator it;
public:
	AnimatedTile(uint32_t tileId, std::vector<uint32_t> tilesId);
	~AnimatedTile();

	void update(const float& dt) override;
	uint32_t getTileId() override { return *it; }
};