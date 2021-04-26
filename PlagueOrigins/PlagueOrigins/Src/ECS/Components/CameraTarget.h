#pragma once

struct CameraTarget
{
	CameraTarget(sf::Vector2f size)
	{
		camera.setSize(size);
	}
	sf::View camera;
};