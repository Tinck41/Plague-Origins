#pragma once

#include "box2d/box2d.h"
#include "entt.hpp"
#include "PhysicsContactListener.h"

#define RADTODEG 180.f / M_PI
#define SCALE 30.f

enum EntityCategory
{
	PLAYER = 0x0001,
	ENEMY_NPC = 0x0002,
	FRIENDLY_NPC = 0x0004,
	OBSTACLE = 0x0006,
	ENEMY_AGGRO_RADIUS = 0x0007,
	ATTACK_RADIUS = 0x0008,
	BOSS_FIGHT_TRIGGER = 0x0009
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

	static b2Body* createRectangleBody(sf::Vector2f position, sf::Vector2f size, bool isDynamic, entt::entity owner, uint16 categoryBits);
	static b2Body* createCircleBody(sf::Vector2f position, float radius, bool isDynamic, entt::entity owner, uint16 categoryBits);

	static b2World* getWorld() { return get().world; }

	static float angleBetween(const sf::Vector2f& vec1, const sf::Vector2f& vec2);

private:
	b2World* world;
	PhysicsContactListener contactListener;

	PhysicsWorld();

	void updateInternal(const float& dt);

	b2Body* createRectangleBodyInternal(sf::Vector2f position, sf::Vector2f size, bool isDynamic, entt::entity owner, uint16 categoryBits);
	b2Body* createCircleBodyInternal(sf::Vector2f position, float radius, bool isDynamic, entt::entity owner, uint16 categoryBits);
};
