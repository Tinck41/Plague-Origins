#pragma once
#include "MovementComponent.h"
#include <cmath>

MovementComponent::MovementComponent(sf::RectangleShape& shape, int speed)
{
	this->shape = shape;
	this->speed = speed;
	dx = 0;
	dy = 0;
	roll = false;
}

MovementComponent::~MovementComponent()
{

}

void MovementComponent::move(const float& dt)
{
	dx = 0;
	dy = 0;
	roll = false;
	speed = 200;
	state = "IDLE";

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		std::cout << "W is pressed\n";
		std::cout << "shape pos x: " << this->shape.getPosition().x << " shape pos y: " << this->shape.getPosition().y << "\n";
		dy = -1;
		state = "RUN_UP";
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		std::cout << "S is pressed\n";
		std::cout << "shape pos x: " << this->shape.getPosition().x << " shape pos y: " << this->shape.getPosition().y << "\n";
		dy = 1;
		state = "RUN_DOWN";
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		std::cout << "A is pressed\n";
		std::cout << "shape pos x: " << this->shape.getPosition().x << " shape pos y: " << this->shape.getPosition().y << "\n";
		dx = -1;
		state = "RUN_LEFT";
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		std::cout << "D is pressed\n";
		std::cout << "shape pos x: " << this->shape.getPosition().x << " shape pos y: " << this->shape.getPosition().y << "\n";
		dx = 1;
		state = "RUN_RIGHT";
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && !roll)// && (!dx && !dy || !dx || !dy))
	{
		std::cout << "Do a barrel roll\n";
		speed = 800;
		roll = true;
		state = "ROLL";
	}
	if (!dx && !dy) 
		speed = sqrt(speed);

	this->shape.move(sf::Vector2f(dx * speed * dt, dy * speed * dt));
}


void MovementComponent::update(const float& dt)
{
	std::cout << getState() << std::endl;
	this->move(dt);

}

sf::RectangleShape MovementComponent::getShape()
{
	return this->shape;
}

std::string MovementComponent::getState()
{
	return this->state;
}
