#pragma once

#include "stdafx.h"

class Game
{
private:
	sf::RenderWindow* window;
	sf::Event ev;
	sf::Clock dtClock;

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

