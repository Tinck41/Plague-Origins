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

	// �������������
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

