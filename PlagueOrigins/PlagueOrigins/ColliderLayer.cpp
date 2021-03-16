#include "stdafx.h"
#include "ColliderLayer.h"

ColliderLayer::ColliderLayer(sf::Vector2f position, sf::Vector2f size)
{
	this->object.setPosition(position);
	this->object.setSize(size);
}

ColliderLayer::ColliderLayer()
{
}

ColliderLayer::~ColliderLayer()
{
}