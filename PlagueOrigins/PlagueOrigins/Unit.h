#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "SFML/Graphics/RenderWindow.hpp"
#include <iostream>
#include "MovementComponent.h"
#include "ColliderComponent.h"

class Unit
{
private:
	//Variables
	int speed;
	float dx;
	float dy;

	//Game objects
	sf::RectangleShape shape;

	void initVariables();
	void spawnUnit();
protected:
	MovementComponent* movementComponent;
	ColliderComponent* colliderComponent;
public:
	//Constructors/Destructors
	Unit();
	//virtual ~Player();

	//Functions
	void createMovementComponent(sf::RectangleShape& shape, int speed);
	void createColliderComponent(sf::RectangleShape& shape);

	virtual void update(const float& dt);

	virtual void render(sf::RenderWindow* window);
};



