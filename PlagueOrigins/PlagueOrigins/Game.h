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

