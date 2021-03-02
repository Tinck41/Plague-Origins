#pragma once
#include "Unit.h"

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

	enum key
	{
		NONE, IDLE, RUN_UP, RUN_LEFT, RUN_DOWN, RUN_RIGHT, ROLL
	};

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



