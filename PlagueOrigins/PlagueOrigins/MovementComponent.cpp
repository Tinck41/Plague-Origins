#pragma once
#include "MovementComponent.h"

MovementComponent::MovementComponent(sf::RectangleShape& shape, int speed) :
	shape(shape)
{
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
	speed = 600;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		//std::cout << "W is pressed\n";
		//std::cout << "shape pos x: " << this->shape.getPosition().x << " shape pos y: " << this->shape.getPosition().y << "\n";
		dy = -1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		//std::cout << "S is pressed\n";
		//std::cout << "shape pos x: " << this->shape.getPosition().x << " shape pos y: " << this->shape.getPosition().y << "\n";
		dy = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		//std::cout << "A is pressed\n";
		//std::cout << "shape pos x: " << this->shape.getPosition().x << " shape pos y: " << this->shape.getPosition().y << "\n";
		dx = -1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		//std::cout << "D is pressed\n";
		//std::cout << "shape pos x: " << this->shape.getPosition().x << " shape pos y: " << this->shape.getPosition().y << "\n";
		dx = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && !roll)// && (!dx && !dy || !dx || !dy))
	{
		//std::cout << "Do a barrel roll\n";
		speed = 800;
		roll = true;
	}

	this->shape.move(sf::Vector2f(dx * speed * dt, dy * speed * dt));
}


void MovementComponent::update(const float& dt)
{
	this->move(dt);
}

sf::RectangleShape MovementComponent::getShape()
{
	return this->shape;
}