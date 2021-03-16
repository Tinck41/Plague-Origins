#pragma once

#include "ColliderComponent.h"

class ColliderLayer
{
private:
	sf::RectangleShape object;
public:
	ColliderLayer(sf::Vector2f position, sf::Vector2f size);
	ColliderLayer();
	~ColliderLayer();

	ColliderComponent getCollider() { return ColliderComponent(this->object); }
};

