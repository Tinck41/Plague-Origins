#include "stdafx.h"
#include "GameObjects.h"
#include "Unit.h"

GameObjects::GameObjects()
{
	player = std::list<Unit*>();
	enemies = std::list<Unit*>();
	obstacles = std::list<Unit*>();
}

GameObjects::~GameObjects()
{
	player.clear();
	enemies.clear();
	obstacles.clear();
}

GameObjects& GameObjects::Instance()
{
	static GameObjects gObjects;
	return gObjects;
}

void GameObjects::registerObject(Unit* unit, objects e)
{
	switch (e)
	{
	case objects::player:
		player.push_back(unit);
		break;
	case objects::enemies:
		enemies.push_back(unit);
		break;
	case objects::obstacles:
		obstacles.push_back(unit);
		break;
	default:
		break;
	}
}

void GameObjects::dropObject(Unit* unit, objects e)
{
	switch (e)
	{
	case objects::player:
		player.remove(unit);
		break;
	case objects::enemies:
		enemies.remove(unit);
		break;
	case objects::obstacles:
		obstacles.remove(unit);
		break;
	default:
		break;
	}
}

std::list<Unit*> GameObjects::getOverlapBounds(sf::CircleShape circle)
{
	std::list<Unit*> hitEnemies;
	for (auto& enemy : enemies)
	{
		auto ss = circle.getGlobalBounds();
		auto dd = enemy->getShape().getLocalBounds();
		if (circle.getGlobalBounds().intersects(enemy->getShape().getGlobalBounds()))
		{
			hitEnemies.push_back(enemy);
		}

	}
	return hitEnemies;
}

bool GameObjects::getPlayerAggro(sf::CircleShape circle)
{
	return circle.getGlobalBounds().intersects(player.front()->getShape().getGlobalBounds());
}
