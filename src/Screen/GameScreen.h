#pragma once

#include "Screen.h"
#include "Tilemap/TileMap.h"
#include "Tilemap/TilemapParser.h"
#include "Screen/Entity.h"
#include "ECS/Components.h"
#include "Utility/GlobalFactory.h"

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

	Entity ring1;
	Entity ring2;

	tgui::GuiSFML gui;

	TilemapParser mapLoader;
	TileMap map;
public:
	static const ScreenType screenType = ScreenType::GAME;

	GameScreen();
	~GameScreen();

	void exit();
	void start();

    void update(const float& dt);
	ScreenType render(sf::RenderWindow&);
};



