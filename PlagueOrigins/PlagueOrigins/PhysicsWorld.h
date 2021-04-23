#pragma once

#include "PhysicsContactListener.h"
#include "EntityCategory.h"

//enum EntityCategory
//{
//	PLAYER = 0x0001,
//	//NPC = 0x0002, // возможно стоит объединить 2 нижних.
//	ENEMY_NPC = 0x0002,
//	FRIENDLY_NPC = 0x0004,
//	OBSTACLE = 0x0008,
//};

struct ag
{
	b2Body* body;
	bool aggro;
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

	static void setPlayerBody(b2Body* body) { get().player = body; }
	static void pushBody(b2Fixture* body, bool value);
	//static std::list<ag> getAggroList() { return get().enemies; }
	static bool* getAggroList() { return get().aggro; }

	static void setAggro(bool value) { get().aggro2 = value; }
	static void setRange(bool value) { get().inRange = value; }
	static bool getAggro() { return get().aggro2; }
	static bool getRange() { return get().inRange; }
	static void update(const float& dt) { get().updateInternal(dt); }
	void reRaycast();

	static b2Body* createRectangleBody(sf::Vector2f position, sf::Vector2f size, bool isDynamic, uint16 categoryBits, uint16 maskBits);
	static b2Body* createCircleBody(sf::Vector2f position, float radius, bool isDynamic, bool isSensor, uint16 categoryBits, uint16 maskBits);

	static b2World* getWorld() { return get().world; }
private:
	b2World* world;
	PhysicsContactListener contactListener;
	bool inRange;
	bool* aggro;
	bool aggro2;
	//std::list<bool> aggro;

	b2Body* player;
	std::list<b2Fixture*> enemies;

	const float SCALE = 30.f;

	PhysicsWorld();
	
	void updateInternal(const float& dt);

	b2Body* createRectangleBodyInternal(sf::Vector2f position, sf::Vector2f size, bool isDynamic, uint16 categoryBits, uint16 maskBits);
	b2Body* createCircleBodyInternal(sf::Vector2f position, float radius, bool isDynamic, bool isSensor, uint16 categoryBits, uint16 maskBits);
};

