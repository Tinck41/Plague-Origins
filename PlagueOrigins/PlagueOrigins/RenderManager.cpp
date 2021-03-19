#include "stdafx.h"
#include "RenderManager.h"

void RenderManager::setPlayer(Player* player)
{
	this->player = player;
}

void RenderManager::setMap(TileMap* gameMap)
{
	this->gameMap = gameMap;
}

void RenderManager::renderPlayer(sf::RenderWindow& target)
{
	target.draw(*player->getArmatureDisplay(), player->getRenderState());
}

void RenderManager::render(sf::RenderWindow& target)
{
	gameMap->renderFirstLayer(target);
	renderPlayer(target);
	gameMap->renderSecondLayer(target);
}
