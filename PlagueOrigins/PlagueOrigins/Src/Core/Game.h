#pragma once

#include "Src/Screen/ScreenHandler.h"
#include "InputBooleans.h"

class Game
{
private:
	ScreenHandler* screenHandler;
	InputBooleans inputBooleans;

	sf::RenderWindow* window;
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