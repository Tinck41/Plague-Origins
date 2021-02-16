#pragma once

#include "stdafx.h"
#include "Player.h"

class Game
{
private:
	sf::RenderWindow* window;
	sf::Event ev;
	sf::Clock dtClock;

	Player* player = new Player();

	float dt;

	//Init
	void initWindow();
	void initVariables();
public:
	//Constructor/Destructor
	Game();
	~Game();

	//Functions
	

	//Update
	void updateDt();
	void updateSFMLEvents();
	void update();

	//Render
	void render();

	//Core
	void run();
};

