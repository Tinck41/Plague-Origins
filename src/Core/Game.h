#pragma once

#include "Screen/ScreenHandler.h"

class Game
{
private:
	ScreenHandler* screenHandler;

	sf::RenderWindow* window;
	sf::Clock deltaTimeClock;

	float deltaTime;
	float lastFPSTime;
	uint32_t fps;

	void setup();
	void updateDeltaTime();
	void update();
	void render();
public:
	Game();
	~Game();

	void run();
};