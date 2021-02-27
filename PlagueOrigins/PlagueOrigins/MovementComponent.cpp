#pragma once
#include "MovementComponent.h"
#include <cmath>

MovementComponent::MovementComponent(sf::RectangleShape& shape, int speed) :
	shape(shape)
{
	this->speed = speed;
	sqrSpeed = sqrt(speed);
	dx = 0;
	dy = 0;
	roll = false;
	isStateChanged = false;
	state = NONE;
	prevState = NONE;
}

//TEXTURE
//MovementComponent::MovementComponent(sf::Texture& texture, int speed) :
//	texture(texture)
//{
//	this->speed = speed;
//	dx = 0;
//	dy = 0;
//	roll = false;
//}

MovementComponent::~MovementComponent()
{

}

void MovementComponent::move(const float& dt)
{
	//reset
	dx = 0;
	dy = 0;
	roll = false;
	speed = 600;

	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		//std::cout << "W is pressed\n";
		//std::cout << "shape pos x: " << this->shape.getPosition().x << " shape pos y: " << this->shape.getPosition().y << "\n";
		dy = -1;
		prevState = state;
		state = RUN_UP;
		std::cout << prevState << " " << state << std::endl;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		//std::cout << "S is pressed\n";
		//std::cout << "shape pos x: " << this->shape.getPosition().x << " shape pos y: " << this->shape.getPosition().y << "\n";
		dy = 1;
		prevState = state;
		state = RUN_DOWN;
		std::cout << prevState << " " << state << std::endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		//std::cout << "A is pressed\n";
		//std::cout << "shape pos x: " << this->shape.getPosition().x << " shape pos y: " << this->shape.getPosition().y << "\n";
		dx = -1;
		prevState = state;
		state = RUN_LEFT;
		std::cout << prevState << " " << state << std::endl;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		//std::cout << "D is pressed\n";
		//std::cout << "shape pos x: " << this->shape.getPosition().x << " shape pos y: " << this->shape.getPosition().y << "\n";
		dx = 1;
		prevState = state;
		state = RUN_RIGHT;
		std::cout << prevState << " " << state << std::endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && !roll)// && (!dx && !dy || !dx || !dy))
	{
		//std::cout << "Do a barrel roll\n";
		speed = 800;
		roll = true;
		prevState = state;
		state = ROLL;
	}
	if (this->dx == 0 && this->dy == 0)
	{
		prevState = state;
		state = IDLE;
		std::cout << prevState << " " << state << std::endl;
	}
	if (prevState != state)
		stateChanged();

	if (!dx && !dy) 
		speed = sqrSpeed;

	this->shape.move(sf::Vector2f(dx * speed * dt, dy * speed * dt));
}


void MovementComponent::update(const float& dt)
{
	//std::cout << getState() << std::endl;
	this->move(dt);
}

int MovementComponent::getState()
{
	return this->state;
}

sf::Vector2f MovementComponent::getPos()
{
	return this->shape.getPosition();
}

bool MovementComponent::stateChanged()
{
	return prevState != state;
}
