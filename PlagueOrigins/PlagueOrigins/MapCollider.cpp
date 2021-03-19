#include "stdafx.h"
#include "MapCollider.h"

MapCollider::MapCollider(sf::Vector2f position, sf::Vector2f size)
{
	this->object.setPosition(position);
	this->object.setSize(size);
}

MapCollider::MapCollider()
{
}

MapCollider::~MapCollider()
{
}