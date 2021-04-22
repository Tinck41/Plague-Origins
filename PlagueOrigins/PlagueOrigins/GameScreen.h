#pragma once

#include "Screen.h"
#include "Player.h"
#include "TileMap.h"
#include "TileMapLoader.h"
#include "NPCDog.h"
#include "NPCBishop.h"
#include "CameraComponent.h"

#include "GameObjects.h"

class GameScreen :
    public Screen
{
private:
	//GlobalFactory gFactory;
	GameObjects& gObject = GameObjects::Instance();

	Player player{ 2615.f, 2650.f };
	NPCDog npcDog{ 4500.f, 800.f };
	NPCBishop npcBishop{ 4000.f, 200.f };

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



