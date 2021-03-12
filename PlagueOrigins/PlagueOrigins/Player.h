#pragma once
#include "Unit.h"
#include "DirectionFinder.h"
#include "PlayerStateHandler.h"

class Player : public Unit
{
private: 
	//Variables
	sf::RenderStates states;
	int speed;
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
	void createHitbox(float x, float y);
public:
	//Constructors/Destructors
	Player(float x, float y);
	~Player();

	//Functions
	void update(const float& dt);
	void render(sf::RenderWindow& target);

	ColliderComponent getCollider() { return ColliderComponent(this->shape); }

	sf::Vector2f getPosition() { return this->shape.getPosition(); }
};



