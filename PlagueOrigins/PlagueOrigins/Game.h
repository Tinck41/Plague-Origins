#pragma once

#include "ScreenHandler.h"
#include "stdafx.h"

extern Config CONFIG;

class Game
{
private:
	ScreenHandler* screenHandler;
	sf::RenderWindow* window;

	sf::Clock deltaTimeClock;
	float deltaTime;

	void setup();
	void updateDeltaTime();    // Обновляет deltaTime временем отрисовки одного кадра
	void resolveSFMLEvents();  // Обрабатывает события SFML
	void update();
	void render();
public:
	Game();
	~Game();

	void run();
};