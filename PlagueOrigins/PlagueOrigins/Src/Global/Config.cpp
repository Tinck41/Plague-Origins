#include "stdafx.h"

#include "Src/Global/Config.h"

Config::Config()
{
	// Read config.json
	nlohmann::json json;
	std::ifstream i("./Assets/Configs/config.json");
	i >> json;
	
	// Print config.json
	std::cout << "Config" << std::endl;
	std::cout << std::setw(4) << json;

	// Apply config.json
	title = json["title"];
	windowHeight = json["window"]["height"];
	windowWidth = json["window"]["width"];
	isFullscreen = json["window"]["fullscreen"];
	uiHeight = json["window"]["uiHeight"];
	uiWidth = json["window"]["uiWidth"];
	fps = json["fps"];
	font.loadFromFile(json["font"]);

	playerSpeed = json["player"]["speed"];
	playerScale = json["player"]["scale"];
	playerHitpoints = json["player"]["hitpoints"];
	playerDamage = json["player"]["damage"];
	playerHitboxWidth = json["player"]["hitbox"]["width"];
	playerHitboxHeight = json["player"]["hitbox"]["height"];

	dogSpeed = json["dog"]["speed"];
	dogScale = json["dog"]["scale"];
	dogHitpoints = json["dog"]["hitpoints"];
	dogDamage = json["dog"]["damage"];
	dogHitboxWidth = json["dog"]["hitbox"]["width"];
	dogHitboxHeight = json["dog"]["hitbox"]["height"];

	bishopScale = json["bishop"]["scale"];
	bishopHitboxWidth = json["bishop"]["hitbox"]["width"];
	bishopHitboxHeight = json["bishop"]["hitbox"]["height"];
}

Config::~Config()
{
}
