#pragma once

#include "Unit.h"
#include "InputHandler.h"
#include "PlayerStates.h"

class Player : public Unit
{
private: 
	//Variables
	sf::RenderStates states;
	float posX;
	float posY;
	int speed;
	float dx;
	float dy;
	bool isStateChanged;
	float scale;

	InputHandler inputHandler;

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

	sf::Vector2f getPosition() { return this->shape.getPosition(); }
	ColliderComponent getCollider() { return ColliderComponent(this->shape); }
};



