#pragma once
#include "stdafx.h"
#include "ScreenHandler.h"
#include "Player.h"
#include "TileMap.h"
#include "TileMapLoader.h"
#include "SFML/Graphics/RenderWindow.hpp"

class GameScreen :
    public Screen
{
private:
	// Инициализация
	Player* player = new Player(10.0f, 10.0f);

	//Game map
	const char* tileMapSource;
	TileMapLoader mapLoader;
	TileMap map;

	void initMap();
	void initVariables();
public:
	// Конструктор
	GameScreen();

	// Деструктор
	~GameScreen();

    void update(const float& dt);
    void render(sf::RenderWindow&);

	void temporary();
};



