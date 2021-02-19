#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include "Unit.h"

class Player : public Unit
{
private: 
	//Variables
	int speed;
	float dx;
	float dy;

	//Game objects
	sf::RectangleShape shape;

	void initVariables();
	void spawnPlayer(float x, float y);
public:
	//Variables

	//Constructors/Destructors
	Player(float x, float y);
	//virtual ~Player();

	//Functions
	
	void update(const float& dt);

	void render(sf::RenderTarget* target);

};



