#pragma once

#include "PhysicsContactListener.h"

class PhysicsWorld
{
public:
	static PhysicsWorld& get()
	{
		static PhysicsWorld instance;
		return instance;
	}

	PhysicsWorld(PhysicsWorld&) = delete;
	~PhysicsWorld();

	static void update(const float& dt) { get().updateInternal(dt); }

	static b2Body* createRectangleBody(sf::Vector2f position, sf::Vector2f size, bool isDynamic);
	static b2Body* createCircleleBody(sf::Vector2f position, float radius, bool isDynamic);

	static b2World* getWorld() { return get().world; }
private:
	b2World* world;
	PhysicsContactListener contactListener;

	const float SCALE = 30.f;

	PhysicsWorld();
	
	void updateInternal(const float& dt);

	b2Body* createRectangleBodyInternal(sf::Vector2f position, sf::Vector2f size, bool isDynamic);
	b2Body* createCircleBodyInternal(sf::Vector2f position, float radius, bool isDynamic);
};

