#pragma once

#include "ColliderComponent.h"

class MapCollider
{
private:
	sf::RectangleShape object;
public:
	MapCollider(sf::Vector2f position, sf::Vector2f size);
	MapCollider();
	~MapCollider();

	ColliderComponent getCollider() { return ColliderComponent(this->object); }
};

