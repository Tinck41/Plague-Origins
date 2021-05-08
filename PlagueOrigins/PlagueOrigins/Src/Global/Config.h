#pragma once

#include <iomanip>
#include "Src/Utility/json.hpp"

/**
	Stores the configuration of the game.

	Declared in "global.cpp", defined in main.
	*/

class Config {
private:
	unsigned int windowWidth;
	unsigned int windowHeight;
public:
	Config();
	~Config();
	std::string title;
	sf::Font font;
	unsigned int fps;
	bool isFullscreen = false;
	uint16_t uiWidth;
	uint16_t uiHeight;

	int playerSpeed;
	float playerScale;
	float playerHitpoints;
	float playerDamage;
	float playerHitboxWidth;
	float playerHitboxHeight;

	int dogSpeed;
	float dogScale;
	float dogHitpoints;
	float dogDamage;
	float dogHitboxWidth;
	float dogHitboxHeight;

	float bishopScale;
	float bishopHitboxWidth;
	float bishopHitboxHeight;

	unsigned int height()
	{
		return isFullscreen ? sf::VideoMode::getDesktopMode().height : windowHeight;
	}

	unsigned int width() 
	{
		return isFullscreen ? sf::VideoMode::getDesktopMode().width : windowWidth;
	}
};