#pragma once
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
	std::string title;
	sf::Font font;
	unsigned int fps;
	bool isFullscreen = false;

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

	unsigned int height()
	{
		return isFullscreen ? sf::VideoMode::getDesktopMode().height : windowHeight;
	}

	unsigned int width() 
	{
		return isFullscreen ? sf::VideoMode::getDesktopMode().width : windowWidth;
	}
};