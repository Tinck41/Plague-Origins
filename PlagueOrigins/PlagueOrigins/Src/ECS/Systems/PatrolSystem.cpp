#include "stdafx.h"
#include "PatrolSystem.h"

void PatrolSystem::dirToNext(Movement& movement, Patrol& patrol, Transform& transform)
{
	b2Vec2 direction;
	if (transform.position.x < patrol.waypoints[patrol.currentIndex].x - 15.f)
	{
		direction.x = 1.f;
	}
	else if (transform.position.x > patrol.waypoints[patrol.currentIndex].x + 15.f)
	{
		direction.x = -1.f;
	}
	else if (std::fabs(transform.position.x - patrol.waypoints[patrol.currentIndex].x) < 15.f)
	{
		direction.x = 0.f;
	}
	if (transform.position.y < patrol.waypoints[patrol.currentIndex].y - 15.f)
	{
		direction.y = 1.f;
	}
	else if (transform.position.y > patrol.waypoints[patrol.currentIndex].y + 15.f)
	{
		direction.y = -1.f;
	}
	else if (std::fabs(transform.position.y - patrol.waypoints[patrol.currentIndex].y) < 15.f)
	{
		direction.y = 0.f;
	}
	//direction.x = patrol.waypoints[patrol.currentIndex].x - transform.position.x;
	//direction.y = patrol.waypoints[patrol.currentIndex].y - transform.position.y;
	direction.Normalize();
	movement.direction.x = direction.x;
	movement.direction.y = direction.y;
}

void PatrolSystem::nextWaypoint(Patrol& patrol, Transform& transform)
{
	if (std::fabs(transform.position.x - patrol.waypoints[patrol.currentIndex].x) < 15.f
		&& std::fabs(transform.position.y - patrol.waypoints[patrol.currentIndex].y) < 15.f)
	{
		patrol.currentIndex++;
		if (patrol.currentIndex >= patrol.waypoints.size())
			patrol.currentIndex = 0;
	}
}

void PatrolSystem::render(entt::registry& reg, sf::RenderWindow& window, tgui::GuiSFML& gui)
{
	window.draw(marker);
}

void PatrolSystem::update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt)
{
	auto view = reg.view<Movement,Patrol,Transform>();
	for (auto entity : view)
	{
		Movement& movement = reg.get<Movement>(entity);
		Patrol& patrol = reg.get<Patrol>(entity);
		Transform& transform = reg.get<Transform>(entity);
		marker.setPosition(sf::Vector2f(transform.position.x + marker.getRadius(),transform.position.y + marker.getRadius()));
		dirToNext(movement, patrol, transform);
		nextWaypoint(patrol, transform);
	}
}
