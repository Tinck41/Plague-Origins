#pragma once

class Unit;

enum objects
{
	player, enemies, obstacles
};

class GameObjects
{
private:
	//const Unit& player;
	std::list<Unit*> player;
	std::list<Unit*> enemies;
	std::list<Unit*> obstacles;
	GameObjects();
	~GameObjects();
	GameObjects(const GameObjects& root) = delete;
	GameObjects& operator = (const GameObjects&) = delete;
public:
	static GameObjects& Instance();
	void registerObject(Unit* unit, objects e);
	void dropObject(Unit* unit, objects e);
	std::list<Unit*> getOverlapBounds(sf::CircleShape circle);
	bool getPlayerAggro(sf::CircleShape circle);
	Unit* getPlayer() { 
		return player
			.front();
	}
};

