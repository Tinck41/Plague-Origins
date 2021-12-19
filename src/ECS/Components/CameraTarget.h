#pragma once

struct CameraTarget
{
	CameraTarget(sf::Vector2f size, sf::Vector2u worldBounds)
	{
		camera.setSize(size);
		bounds = worldBounds;
	}

	sf::View camera;
	sf::Vector2u bounds;
};