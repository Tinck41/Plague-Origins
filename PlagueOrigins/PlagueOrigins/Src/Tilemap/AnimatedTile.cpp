#include "stdafx.h"

#include "AnimatedTile.h"

AnimatedTile::AnimatedTile(uint32_t tileId, sf::Vector2u tilePosition, std::vector<uint32_t> tilesId, const float& duration) :
	StaticTile(tileId, tilePosition)
{
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
