#include "stdafx.h"
#include "StaticTile.h"

StaticTile::StaticTile(uint32_t tileId, sf::Vector2u tilePosition)
{
	id = tileId;
	position = tilePosition;
}

void StaticTile::update(const float& dt)
{

}
