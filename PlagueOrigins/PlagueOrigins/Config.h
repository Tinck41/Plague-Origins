#pragma once
/**
	Stores the configuration of the game.

	Declared in "global.cpp", defined in main.
	*/
class Config {
private:
	unsigned int WINDOW_WIDTH = 800;
	unsigned int WINDOW_HEIGHT = 600;
public:
	Config();
	unsigned int FPS_LIMIT = 60;
	bool IS_FULLSCREEN = true;

	unsigned int getHeight()
	{
		return IS_FULLSCREEN ? sf::VideoMode::getDesktopMode().height : WINDOW_HEIGHT;
	}

	unsigned int getWidth() 
	{
		return IS_FULLSCREEN ? sf::VideoMode::getDesktopMode().width : WINDOW_WIDTH;
	}
	
	std::string WINDOW_TITLE = "Plague: Origins";
	sf::Font MAIN_FONT;
};