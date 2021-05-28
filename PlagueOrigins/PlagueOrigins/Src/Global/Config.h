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
	float playerAttackRange;
	float playerHitboxWidth;
	float playerHitboxHeight;
	std::vector<int> playerStats = std::vector<int>();

	int dogSpeed;
	float dogScale;
	float dogAttackRange;
	float dogHitboxWidth;
	float dogHitboxHeight;
	std::vector<int> dogStats = std::vector<int>();

	float bishopScale;
	float bishopHitboxWidth;
	float bishopHitboxHeight;
	std::vector<int> bishopStats = std::vector<int>();

	int bossSpeed;
	float bossScale;
	float bossAttackRange;
	float bossHitboxWidth;
	float bossHitboxHeight;
	std::vector<int> bossStats = std::vector<int>();

	unsigned int height()
	{
		return isFullscreen ? sf::VideoMode::getDesktopMode().height : windowHeight;
	}

	unsigned int width() 
	{
		return isFullscreen ? sf::VideoMode::getDesktopMode().width : windowWidth;
	}
};