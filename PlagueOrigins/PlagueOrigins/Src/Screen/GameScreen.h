#pragma once

#include "Screen.h"
#include "Src/Tilemap/TileMap.h"
#include "Src/Tilemap/TilemapParser.h"
#include "Src/Screen/Entity.h"
#include "Src/ECS/Components.h"

class GameScreen :
    public Screen
{
private:
	Entity testEntity;
	Entity npcEntity;
	Entity bishop;

	TilemapParser mapLoader;
	TileMap map;
public:
	static const ScreenType screenType = ScreenType::GAME;

	GameScreen();
	~GameScreen();

    void update(const float& dt);
	ScreenType render(sf::RenderWindow&);
};



