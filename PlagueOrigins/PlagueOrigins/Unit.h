#pragma once
#include "MovementComponent.h"
#include "AnimationComponent.h"
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
	sf::Texture texture;
	sf::View view;

	void initVariables();
	void spawnUnit();
protected:
	MovementComponent* movementComponent;
	AnimationComponent* animationComponent;
	ColliderComponent* colliderComponent;
public:
	//Constructors/Destructors
	Unit();

	//Functions
	void createMovementComponent(sf::RectangleShape& shape, int speed);
	void createAnimationComponent(sf::RectangleShape& shape, dragonBones::SFMLFactory& factory);
	void createColliderComponent(sf::RectangleShape& shape);

	virtual void update(const float& dt);

	virtual void render(sf::RenderWindow* window);

};



