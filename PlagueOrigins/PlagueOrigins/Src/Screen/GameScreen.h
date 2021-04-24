#pragma once

#include "Screen.h"
#include "Player.h"
#include "Src/Tilemap/TileMap.h"
#include "Src/Tilemap/TilemapParser.h"
#include "NPCDog.h"
#include "NPCBishop.h"
#include "CameraComponent.h"
#include "InventoryComponent.h"
#include "Src/Screen/Entity.h"

class GameScreen :
    public Screen
{
private:
	//GlobalFactory gFactory;

	Player player{ 615.f, 350.f };
	NPCDog npcDog{ 1500.f, 700.f };
	NPCBishop npcBishop{ 400.f, 650.f };

	Entity testEntity;
	Entity npcEntity;
	sf::RectangleShape entityShape;

	TilemapParser mapLoader;
	TileMap map;

	CameraComponent* cameraComponent;
	InventoryComponent* inventoryComponent;
public:
	static const ScreenType screenType = ScreenType::GAME;

	GameScreen();
	~GameScreen();

    void update(const float& dt);
	ScreenType render(sf::RenderWindow&);
};



