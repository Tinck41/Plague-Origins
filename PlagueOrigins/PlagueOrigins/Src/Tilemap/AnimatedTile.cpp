#include "stdafx.h"

#include "AnimatedTile.h"

AnimatedTile::AnimatedTile(uint16_t tileId, sf::Vector2u tilePosition, std::vector<uint16_t> tilesId, const float& duration)
{
	id = tileId;
	position = tilePosition;
	this->duration = duration;
	curDuration	= sf::milliseconds(duration);

	this->tilesId = tilesId;
	it = 0;
}

AnimatedTile::~AnimatedTile()
{
	tilesId.clear();
}

void AnimatedTile::update(const float& dt)
{
	if (curDuration <= sf::milliseconds(0))
	{
		curDuration = sf::milliseconds(duration);
		
		id = tilesId[it];
		it++;

		if (it == tilesId.size())
		{
			it = 0;
		}
	}
	else
	{
		curDuration -= sf::seconds(dt);
	}
}

void AnimatedTile::changePosition(sf::Vector2u newPosition)
{
	position = newPosition;
}
