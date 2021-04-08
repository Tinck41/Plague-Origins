#pragma once

#include "Screen.h"
#include "Player.h"
#include "TileMap.h"
#include "TileMapLoader.h"
#include "NPCDog.h"
#include "CameraComponent.h"

class GameScreen :
    public Screen
{
private:
	//GlobalFactory gFactory;

	Player player{ 615.0f, 700.0f };
	NPCDog npcDog{ 1500.0f, 700.0f };

	TileMapLoader mapLoader;
	TileMap map;

	CameraComponent* cameraComponent;
public:
	static const ScreenType screenType = ScreenType::GAME;

	GameScreen();
	~GameScreen();

    void update(const float& dt);
	ScreenType render(sf::RenderWindow&);
};



