#pragma once
#include "Unit.h"
#include "FiniteStateMachine.h"
#include "GlobalFactory.h"
#include "Patrol.h"

class NPCDogIdleState;
class NPCDogMoveState;
class NPCDogAggroState;
class NPCDogDeathState;

class NPCDog :
	public Unit
{
private:
	//Variables
	sf::RenderStates states;
	int speed;
	float scale;
	float hitpoints;
	float damage;

	int pointN;
	//waypoints of rectangle patrol path TEST
	sf::Vector2f point0 = sf::Vector2f(500.0f, 800.0f);
	sf::Vector2f point1 = sf::Vector2f(2000.0f, 800.0f);

	Patrol* patrolComponent;
	std::vector<sf::Vector2f> waypoints;
	sf::Vector2f direction;

	GameObjects& gObjects;
	GlobalFactory& gFactory;
	dragonBones::SFMLFactory& factory;

	FiniteStateMachine* npcDogStateMachine;
	State* initState;

	//Game objects
	sf::RectangleShape shape;

	void fillWaypoints();
	sf::Vector2f getWaypoint(int pointN);

	void initVariables();
	void createHitbox(float x, float y);
	//void findRoute(sf::Vector2f dest);
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
	ColliderComponent* getCollider() { return colliderComponent; }
	AnimationComponent* getAnimator() { return animationComponent; }
	MovementComponent* getMover() { return movementComponent; }
	Patrol* getPatrol() { return patrolComponent; }
	FiniteStateMachine* getStateMachine() { return npcDogStateMachine; }
	float getHP() { return hitpoints; }

	// Setters
	//void setArmature(dragonBones::SFMLArmatureDisplay* armatureDisplay) { this->armatureDisplay = armatureDisplay; }
};

