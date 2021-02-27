#pragma once

#include "Screen.h"
#include "Player.h"
#include "TileMap.h"
#include "TileMapLoader.h"

extern Config CONFIG;

class GameScreen :
    public Screen
{
private:
	Player* player;
	TileMapLoader mapLoader;
	TileMap map;

	void setup();
public:
	static const ScreenType screenType = ScreenType::GAME;

	GameScreen();
	~GameScreen();

    void update(const float& dt);
	ScreenType render(sf::RenderWindow&);
};



