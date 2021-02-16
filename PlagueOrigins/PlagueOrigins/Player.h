#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>

class Player 
{
private: 
	//Variables
	sf::Event ev;

	

	int speed;
	float dx;
	float dy;

	//Game objects
	sf::RectangleShape playerShape;
	sf::Sprite playerSprite;

	void initVariables();
	void spawnPlayer();
public:
	//Variables
	bool isWPressed;
	bool isAPressed;
	bool isSPressed;
	bool isDPressed;

	//Constructors/Destructors
	Player();
	//virtual ~Player();

	//Functions

	void update(float dt);

	void move(float dt);

	void render(sf::RenderTarget* target);

};



