#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>

class Unit
{
private:
	//Variables
	int speed;
	float dx;
	float dy;

	//Game objects
	sf::RectangleShape unitShape;
	sf::Sprite unitSprite;

	void initVariables();
	void spawnUnit();
public:
	//Variables
	bool isWPressed;
	bool isAPressed;
	bool isSPressed;
	bool isDPressed;

	//Constructors/Destructors
	Unit();
	//virtual ~Player();

	//Functions

	void update(float dt);

	void move(sf::RectangleShape rShape, float dt);

	void render(sf::RenderTarget* target);

};



