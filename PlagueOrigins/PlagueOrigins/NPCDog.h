#pragma once
#include "Unit.h"

class NPCDog :
	public Unit
{
	//Variables
	sf::RenderStates states;
	int speed;
	float scale;

	int pointN;
	//waypoints of rectangle patrol path TEST
	sf::Vector2f point0 = sf::Vector2f(1500.0f, 700.0f);
	sf::Vector2f point1 = sf::Vector2f(2000.0f, 700.0f);
	//sf::Vector2f point2 = sf::Vector2f(3000.0f, 3000.0f);
	//sf::Vector2f point3 = sf::Vector2f(2000.0f, 3000.0f);

	std::vector<sf::Vector2f> waypoints;
	sf::Vector2f direction;

	GlobalFactory& gFactory;
	dragonBones::SFMLFactory& factory;

	//Game objects
	sf::RectangleShape shape;

	void fillWaypoints();
	sf::Vector2f getWaypoint(int pointN);

	void initVariables();
	void createHitbox(float x, float y);
	void patrol();
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
	sf::Vector2f getPosition() { return this->shape.getPosition(); }
	ColliderComponent getCollider() { return ColliderComponent(this->shape); }
	AnimationComponent* getAnimator() { return this->animationComponent; }
	MovementComponent* getMover() { return this->movementComponent; }

	// Setters
	//void setArmature(dragonBones::SFMLArmatureDisplay* armatureDisplay) { this->armatureDisplay = armatureDisplay; }
};

