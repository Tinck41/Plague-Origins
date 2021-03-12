#pragma once

#include "Unit.h"
#include "DirectionFinder.h"
#include "PlayerStates.h"
#include "IStateHandler.h"
#include "PlayerStateHandler.h"

class Player : public Unit
{
private: 
	//Variables
	sf::RenderStates states;
	float posX;
	float posY;
	int speed;
	bool isStateChanged;
	float scale;

	InputBooleans inputBooleans;
	DirectionFinder directionFinder;
	PlayerStateHandler playerStateHandler;

	//Game objects
	sf::RectangleShape shape;

	//dragonBones
	dragonBones::SFMLFactory factory;
	dragonBones::SFMLArmatureDisplay* armatureDisplay;

	void initVariables();
	void spawnPlayer(float x, float y);
public:
	//Variables

	//Constructors/Destructors
	Player();
	Player(float x, float y);
	~Player();
	//virtual ~Player();

	//Functions
	
	void update(const float& dt);
	void render(sf::RenderWindow& target);

	ColliderComponent getCollider() { return ColliderComponent(this->shape); }

	sf::Vector2f getPosition() { return this->shape.getPosition(); }
};



