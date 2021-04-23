#pragma once

#include "Unit.h"
#include "FiniteStateMachine.h"
#include "DirectionFinder.h"
//#include "PlayerStateHandler.h"
#include "GlobalFactory.h"

class PlayerIdleState;
class PlayerMoveState;

class Player : 
	public Unit
{
private: 
	//Variables
	sf::RenderStates states;
	int speed;
	float scale;

	float hitpoints;
	float damage;

	DirectionFinder directionFinder;
	//PlayerStateHandler playerStateHandler;

	FiniteStateMachine* playerStateMachine;
	State* initState;

	//Game objects
	sf::RectangleShape shape;

	GameObjects& gObjects;
	GlobalFactory& gFactory;
	//dragonBones
	dragonBones::SFMLFactory& factory;
	//std::unique_ptr<dragonBones::SFMLArmatureDisplay> armatureDisplay;

	void initVariables();
	void createHitbox(float x, float y);
public:
	//Constructors/Destructors
	Player(float x, float y);
	Player();
	~Player();

	Player(const Player&) = default;
	Player& operator=(const Player&) = default;

	//Functions
	void update(const float& dt);
	void render(sf::RenderWindow& target);

	// Getters
	sf::RectangleShape getShape() override { return shape; } 
	sf::Vector2f getPosition() { return shape.getPosition(); }
	ColliderComponent* getCollider() { return colliderComponent; }
	DirectionFinder getInput() { return directionFinder; }
	AnimationComponent* getAnimator() { return animationComponent; }
	MovementComponent* getMover() { return movementComponent; }
	FiniteStateMachine* getStateMachine() { return playerStateMachine; }
	float getHP() { return hitpoints; }

	// Setters
	//void setArmature(dragonBones::SFMLArmatureDisplay* armatureDisplay) { this->armatureDisplay = armatureDisplay; }
};