#pragma once

#include "Screen.h"
#include "Player.h"
#include "TileMap.h"
#include "TileMapLoader.h"
#include "ColliderComponent.h"

extern Config CONFIG;

class GameScreen :
    public Screen
{
private:
	Player player{ 615.0f, 350.0f };
	TileMapLoader mapLoader;
	TileMap map;

	sf::View camera;

	void setup();
public:
	static const ScreenType screenType = ScreenType::GAME;

	GameScreen();
	~GameScreen();

    void update(const float& dt);
	ScreenType render(sf::RenderWindow&);
};



