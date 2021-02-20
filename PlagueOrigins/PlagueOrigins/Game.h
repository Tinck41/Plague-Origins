#pragma once

#include "stdafx.h"
#include "ScreenHandler.hpp"
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

	// �������������
	Player* player = new Player(10.0f, 10.0f);

	//Game map
	const char* tileMapSource;
	TileMapLoader mapLoader;
	TileMap map;

	//Init
	void initMap();
	void initWindow();
	void initVariables();
public:
	// �����������
	Game();

	// ����������
	~Game();

	// ����������
	void updateDt();
	void updateSFMLEvents();
	void update();

	// ������
	void render();

	// ����
	void run();
};

