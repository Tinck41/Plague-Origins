#pragma once

class Tile
{
protected:
	uint32_t tileId;
public:
	Tile(uint32_t tileId);
	virtual ~Tile();

	virtual void update(const float& dt) {}
	virtual uint32_t getTileId() { return tileId; }
};