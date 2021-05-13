#include "PatrolSystem.h"

void PatrolSystem::dirToNext(Movement& movement, Patrol& patrol, Transform& transform)
{
	movement.direction = transform.position - patrol.waypoints[0];
}

sf::Vector2f PatrolSystem::nextWaypoint(Patrol& patrol)
{
	patrol.currentWaypoint++;
	if (patrol.currentWaypoint >= patrol.waypoints.size())
		patrol.currentWaypoint = 0;
}

void PatrolSystem::update(entt::registry& reg, const float& dt)
{
	auto view = reg.view<Movement,Patrol,Transform>();
	for (auto entity : view)
	{
		Movement& movement = reg.get<Movement>(entity);
		Patrol& patrol = reg.get<Patrol>(entity);
		Transform& transform = reg.get<Transform>(entity);

		dirToNext(movement, patrol, transform);
	}
}
