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
	playerAttackRange = json["player"]["range"];
	playerHitboxWidth = json["player"]["hitbox"]["width"];
	playerHitboxHeight = json["player"]["hitbox"]["height"];
	playerStats.push_back(json["player"]["stats"]["vit"]);
	playerStats.push_back(json["player"]["stats"]["end"]);
	playerStats.push_back(json["player"]["stats"]["str"]);
	playerStats.push_back(json["player"]["stats"]["agi"]);
	playerStats.push_back(json["player"]["stats"]["int"]);

	dogSpeed = json["dog"]["speed"];
	dogScale = json["dog"]["scale"];
	dogAttackRange = json["dog"]["range"];
	dogHitboxWidth = json["dog"]["hitbox"]["width"];
	dogHitboxHeight = json["dog"]["hitbox"]["height"];
	dogStats.push_back(json["dog"]["stats"]["vit"]);
	dogStats.push_back(json["dog"]["stats"]["end"]);
	dogStats.push_back(json["dog"]["stats"]["str"]);
	dogStats.push_back(json["dog"]["stats"]["agi"]);
	dogStats.push_back(json["dog"]["stats"]["int"]);

	bishopScale = json["bishop"]["scale"];
	bishopHitboxWidth = json["bishop"]["hitbox"]["width"];
	bishopHitboxHeight = json["bishop"]["hitbox"]["height"];
	bishopStats.push_back(json["bishop"]["stats"]["vit"]);
	bishopStats.push_back(json["bishop"]["stats"]["end"]);
	bishopStats.push_back(json["bishop"]["stats"]["str"]);
	bishopStats.push_back(json["bishop"]["stats"]["agi"]);
	bishopStats.push_back(json["bishop"]["stats"]["int"]);

	bossSpeed = json["boss"]["speed"];
	bossScale = json["boss"]["scale"];
	bossAttackRange = json["boss"]["range"];
	bossHitboxWidth = json["boss"]["hitbox"]["width"];
	bossHitboxHeight = json["boss"]["hitbox"]["height"];
	bossStats.push_back(json["boss"]["stats"]["vit"]);
	bossStats.push_back(json["boss"]["stats"]["end"]);
	bossStats.push_back(json["boss"]["stats"]["str"]);
	bossStats.push_back(json["boss"]["stats"]["agi"]);
	bossStats.push_back(json["boss"]["stats"]["int"]);
}

Config::~Config()
{
}
