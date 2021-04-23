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

	int playerVIT;
	int playerEND;
	int playerSTR;
	int playerAGI;
	int playerINT;
	int playerHUM;

	int dogSpeed;
	float dogScale;
	float dogHitpoints;
	float dogDamage;
	float dogHitboxWidth;
	float dogHitboxHeight;

	int dogVIT;
	int dogEND;
	int dogSTR;
	int dogAGI;
	int dogINT;
	int dogHUM;

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