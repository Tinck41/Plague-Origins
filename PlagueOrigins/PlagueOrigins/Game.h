#pragma once

#include "ScreenHandler.h"

extern Config CONFIG;

class Game
{
private:
	ScreenHandler* screenHandler;
	sf::RenderWindow* window;
	InputBooleans inputBooleans;

	sf::Clock deltaTimeClock;
	float deltaTime;

	void setup();
	void updateDeltaTime();
	void resolveSFMLEvents();
	void update();
	void render();
public:
	Game();
	~Game();

	void run();
};