#pragma once
#include "Unit.h"
#include "DirectionFinder.h"
#include <vector>

class NPC : public Unit
{
private:
	sf::RenderStates states;
	int speed;
	float scale;


	//move to new PatrolComponent?
	int pointN;
	//waypoints of rectangle patrol path TEST
	sf::Vector2f point0 = sf::Vector2f(1000.0f, 200.0f);
	sf::Vector2f point1 = sf::Vector2f(1000.0f, 1000.0f);
	//sf::Vector2f point2 = sf::Vector2f(3000.0f, 3000.0f);
	//sf::Vector2f point3 = sf::Vector2f(2000.0f, 3000.0f);

	std::vector<sf::Vector2f> waypoints;

	sf::Vector2f direction;
	//DirectionFinder directionFinder;

	sf::RectangleShape shape;

	void fillWaypoints();
	sf::Vector2f getWaypoint(int pointN);

	void initVariables();
	void createHitbox(float x, float y);
	void pathBuild(sf::Vector2f v);
public:
	NPC(float x, float y);

	void update(const float& dt);
	void render(sf::RenderWindow& target);

	ColliderComponent getCollider() { return ColliderComponent(this->shape); }

	sf::Vector2f getPosition() { return this->shape.getPosition(); }
};

