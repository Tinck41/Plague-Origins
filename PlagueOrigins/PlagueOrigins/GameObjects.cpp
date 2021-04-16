#include "stdafx.h"
#include "GameObjects.h"
#include "Unit.h"

GameObjects::GameObjects()
{
	player = std::list<Unit*>();
	enemies = std::list<Unit*>();
	obstacles = std::list<Unit*>();
	merchants = std::list<Unit*>();
}

GameObjects::~GameObjects()
{
	player.clear();
	enemies.clear();
	obstacles.clear();
	merchants.clear();
}

GameObjects& GameObjects::Instance()
{
	static GameObjects gObjects;
	return gObjects;
}

void GameObjects::registerObject(Unit* unit, objects e)
{
	unit->setActiveStatus(true);
	switch (e)
	{
	case objects::player:
		player.push_back(unit);
		break;
	case objects::enemies:
		enemies.push_back(unit);
		break;
	case objects::merchants:
		merchants.push_back(unit);
		break;
	case objects::obstacles:
		obstacles.push_back(unit);
		break;
	default:
		break;
	}
}

Unit* GameObjects::getUnitById(int id, objects e)
{
	switch (e)
	{
	case objects::player:
		return player.front();
		break;
	case objects::enemies:
		for (auto& enemy : enemies)
		{
			if (enemy->getId() == id)
				return enemy;
		}
		break;
	case objects::merchants:
		for (auto& merchant : merchants)
		{
			if (merchant->getId() == id)
				return merchant;
		}
		break;
	case objects::obstacles:
		for (auto& obstacle : obstacles)
		{
			if (obstacle->getId() == id)
				return obstacle;
		}
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
	case objects::merchants:
		merchants.remove(unit);
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

bool GameObjects::getPlayerInteraction(sf::RectangleShape rect)
{
	return rect.getGlobalBounds().intersects(player.front()->getShape().getGlobalBounds());
}
