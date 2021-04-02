#pragma once
#include "Unit.h"
#include "FiniteStateMachine.h"
#include "GlobalFactory.h"
#include "Patrol.h"

class NPCDogIdleState;
class NPCDogMoveState;

//struct ptrl
//{
//	sf::Vector2f direction;
//	animationName animationName;
//};

class NPCDog :
	public Unit
{
	//Variables
	sf::RenderStates states;
	int speed;
	float scale;
	float hitpoints;
	float damage;

	int pointN;
	//waypoints of rectangle patrol path TEST
	sf::Vector2f point0 = sf::Vector2f(1500.0f, 700.0f);
	sf::Vector2f point1 = sf::Vector2f(2000.0f, 700.0f);

	Patrol* patrolComponent;
	std::vector<sf::Vector2f> waypoints;
	sf::Vector2f direction;

	GameObjects& gObjects;
	GlobalFactory& gFactory;
	dragonBones::SFMLFactory& factory;

	FiniteStateMachine* playerStateMachine;
	State* initState;

	//Game objects
	sf::RectangleShape shape;

	void fillWaypoints();
	sf::Vector2f getWaypoint(int pointN);

	void initVariables();
	void createHitbox(float x, float y);
	void findRoute(sf::Vector2f dest);
public:
	//Constructors/Destructors
	NPCDog(float x, float y);
	~NPCDog();

	NPCDog(const NPCDog&) = default;
	NPCDog& operator=(const NPCDog&) = default;

	//Functions
	void update(const float& dt);
	void render(sf::RenderWindow & target);

	// Getters
	sf::RectangleShape getShape() override { return shape; }
	sf::Vector2f getPosition() { return shape.getPosition(); }
	ColliderComponent getCollider() { return ColliderComponent(shape); }
	AnimationComponent* getAnimator() { return animationComponent; }
	MovementComponent* getMover() { return movementComponent; }
	Patrol* getPatrol() { return patrolComponent; }
	FiniteStateMachine* getStateMachine() { return playerStateMachine; }

	// Setters
	//void setArmature(dragonBones::SFMLArmatureDisplay* armatureDisplay) { this->armatureDisplay = armatureDisplay; }
};
