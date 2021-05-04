#pragma once

#include "StaticTile.h"

class AnimatedTile :
	public StaticTile
{
protected:
	float duration;
	sf::Time curDuration;

	std::vector<uint32_t> tilesId;
	size_t it;
public:
	AnimatedTile(uint32_t tileId, sf::Vector2u tilePosition, std::vector<uint32_t> tilesId, const float& duration = 0);
	~AnimatedTile();

	virtual void update(const float& dt);

	void changePosition(sf::Vector2u newPosition);
};