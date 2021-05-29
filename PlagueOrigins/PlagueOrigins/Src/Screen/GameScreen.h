#pragma once

#include "Screen.h"
#include "Src/Tilemap/TileMap.h"
#include "Src/Tilemap/TilemapParser.h"
#include "Src/Screen/Entity.h"
#include "Src/ECS/Components.h"
#include "Src/Utility/GlobalFactory.h"

class GameScreen :
    public Screen
{
private:
	Entity screenManager;
	Entity playerEnt;
	Entity bishopEnt1;
	Entity bishopEnt2;
	Entity bossEnt;
	Entity dogEnt1;
	Entity dogEnt2;
	Entity dogEnt3;
	Entity dogEnt4;
	Entity dogEnt5;
	Entity dogEnt6;
	Entity dogEnt7;

	tgui::GuiSFML gui;

	TilemapParser mapLoader;
	TileMap map;
public:
	static const ScreenType screenType = ScreenType::GAME;

	GameScreen();
	~GameScreen();

    void update(const float& dt);
	ScreenType render(sf::RenderWindow&);
};



