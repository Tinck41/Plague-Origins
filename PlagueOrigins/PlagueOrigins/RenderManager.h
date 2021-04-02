#pragma once

#include "Player.h"
#include "TileMap.h"

class RenderManager
{
private:
	// Game objects
	Player* player;
	TileMap* gameMap;

	void renderPlayer(sf::RenderWindow& target);
public:
	void setPlayer(Player* player);
	void setMap(TileMap* gameMap);

	void render(sf::RenderWindow& target);
};

