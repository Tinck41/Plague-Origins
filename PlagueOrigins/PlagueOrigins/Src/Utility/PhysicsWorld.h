#pragma once

#include "box2d/box2d.h"
#include "PhysicsContactListener.h"

enum EntityCategory
{
	PLAYER = 0x0001,
	//NPC = 0x0002,
	ENEMY_NPC = 0x0002,
	FRIENDLY_NPC = 0x0004,
	OBSTACLE = 0x0006,
};

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

	static b2Body* createRectangleBody(sf::Vector2f position, sf::Vector2f size, bool isDynamic, uint16 categoryBits, uint16 maskBits);
	static b2Body* createCircleleBody(sf::Vector2f position, float radius, bool isDynamic, uint16 categoryBits, uint16 maskBits);

	static b2World* getWorld() { return get().world; }
private:
	b2World* world;
	PhysicsContactListener contactListener;

	const float SCALE = 30.f;

	PhysicsWorld();

	void updateInternal(const float& dt);

	b2Body* createRectangleBodyInternal(sf::Vector2f position, sf::Vector2f size, bool isDynamic, uint16 categoryBits, uint16 maskBits);
	b2Body* createCircleBodyInternal(sf::Vector2f position, float radius, bool isDynamic, uint16 categoryBits, uint16 maskBits);
};
