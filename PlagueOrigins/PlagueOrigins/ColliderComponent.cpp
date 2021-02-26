#include "stdafx.h"

#include "ColliderComponent.h"

ColliderComponent::ColliderComponent(sf::RectangleShape& body) :
	body(body)
{
	
}

ColliderComponent::~ColliderComponent()
{
}

bool ColliderComponent::checkCollision(ColliderComponent other, float push)
{
	sf::Vector2f otherPosition = other.getPosition();
	sf::Vector2f otherHalfSize = other.getHalfSize();
	sf::Vector2f thisPosition = this->getPosition();
	sf::Vector2f thisHalfSize = this->getHalfSize();

	float deltaX = (otherPosition.x + otherHalfSize.x) - (thisPosition.x + thisHalfSize.x);
	float deltaY = (otherPosition.y + otherHalfSize.y) - (thisPosition.y + thisHalfSize.y);
	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		std::cout << deltaX << " " << deltaY << std::endl;

		push = std::min(std::max(push, 0.0f), 1.0f);

		if (intersectX > intersectY)
		{
			if (deltaX > 0.0f)
			{
				this->move(intersectX * (1.0f - push), 0.0f);
				other.move(-intersectX * push, 0.0f);
			}
			else
			{
				this->move(-intersectX * (1.0f - push), 0.0f);
				other.move(intersectX * push, 0.0f);
			}
		}
		else
		{
			if (deltaY > 0.0f)
			{
				this->move(0.0f, intersectY * (1.0f - push));
				other.move(0.0f, -intersectY * push);
			}
			else
			{
				this->move(0.0f, -intersectY * (1.0f - push));
				other.move(0.0f, intersectY * push);
			}
		}

		return true;
	}

	return false;
}
