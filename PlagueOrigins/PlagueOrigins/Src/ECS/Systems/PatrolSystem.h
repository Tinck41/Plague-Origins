#pragma once
#include "IUpdateSystem.h"
#include "Src/ECS/Components.h"

class PatrolSystem 
	: IUpdateSystem
{
	void dirToNext(Movement& movement, Patrol& patrol, Transform& transform);
	sf::Vector2f nextWaypoint(Patrol& patrol);

	// Inherited via IUpdateSystem
	virtual void update(entt::registry& reg, const float& dt) override;

};