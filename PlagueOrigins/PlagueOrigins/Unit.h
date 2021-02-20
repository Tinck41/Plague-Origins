#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include "MovementComponent.h"

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

public:
	//Constructors/Destructors
	Unit();
	//virtual ~Player();

	//Functions
	void createMovementComponent(sf::RectangleShape& shape, int speed);

	virtual void update(const float& dt) = 0;

	virtual void render(sf::RenderTarget* target) = 0;

};



