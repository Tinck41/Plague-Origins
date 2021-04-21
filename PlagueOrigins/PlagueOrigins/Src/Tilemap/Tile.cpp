#include "stdafx.h"

#include "Tile.h"

Tile::Tile(uint32_t tileId, std::vector<uint32_t> tilesId, bool isAnimated, const float& duration)
{
	this->tileId = tileId;
	this->tilesId = tilesId;
	this->isAniamted = isAnimated;

	this->duration = duration;
	curDuration = sf::milliseconds(duration);

	itSet = false;
}

Tile::~Tile()
{
	tilesId.clear();
}

void Tile::update(const float& dt)
{
	if (isAniamted)
	{
		if (!itSet)
		{
			itSet = true;
			it = tilesId.begin();
		}

		if (curDuration <= sf::milliseconds(0))
		{
			curDuration = sf::milliseconds(duration);

			it++;

			if (it == tilesId.end())
			{
				it = tilesId.begin();
			}
		}
		else
		{
			curDuration -= sf::seconds(dt);
		}
	}
}

uint32_t Tile::getPlayingTileId()
{
	return isAniamted ? *it : 0;
}