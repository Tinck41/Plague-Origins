#pragma once
#include "stdafx.h"

/**
	Stores the configuration of the game.

	Declared in "global.cpp", defined in main.
	*/
class Config {
public:
	Config();
	unsigned int WINDOW_WIDTH = 800;
	unsigned int WINDOW_HEIGHT = 600;
	unsigned int FPS_LIMIT = 60;
	bool IS_FULLSCREEN = false;
	
	std::string WINDOW_TITLE = "Plague: Origins";
	sf::Font MAIN_FONT;
};