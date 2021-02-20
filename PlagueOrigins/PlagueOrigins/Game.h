#pragma once

#include "stdafx.h"
#include "ScreenHandler.h"
#include "Player.h"
#include "TileMap.h"
#include "TileMapLoader.h"

class Game
{
private:
	ScreenHandler *screenHandler;
	sf::RenderWindow *window;
	sf::Event ev;
	
	//Delta time
	sf::Clock dtClock;
	float dt;

	// Init
	// initMap();
	void initWindow();
	void initVariables();
public:
	// Конструктор
	Game();

	// Деструктор
	~Game();

	// Обновление
	void updateDt();
	void updateSFMLEvents();
	void update();

	// Рендер
	void render();

	// Ядро
	void run();
};

