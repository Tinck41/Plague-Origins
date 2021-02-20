#pragma once

#include "stdafx.h"
#include "ScreenHandler.hpp"

class Game
{
private:
	ScreenHandler *screenHandler;
	sf::RenderWindow *window;
	sf::Event ev;
	sf::Clock dtClock;

	float dt;

	// Инициализация
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

