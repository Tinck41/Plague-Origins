#pragma once

class Tile
{
protected:
	uint32_t tileId;

	float duration;
	sf::Time curDuration;

	bool isAniamted;
	bool itSet;

	std::vector<uint32_t> tilesId;
	std::vector<uint32_t>::iterator it;
public:
	Tile(uint32_t tileId, std::vector<uint32_t> tilesId, bool isAnimated, const float& duration = 0);
	virtual ~Tile();

	bool Animated() { return isAniamted; }

	void update(const float& dt);

	uint32_t getTileId() { return tileId; }
	uint32_t getPlayingTileId();
};