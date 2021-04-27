#include "stdafx.h"
#include "Camera.h"

void Camera::render(entt::registry& reg, sf::RenderWindow& window)
{
	auto view = reg.view<CameraTarget, Transform>();
	for (auto entity : view)
	{
		CameraTarget& target = reg.get<CameraTarget>(entity);
		Transform& transform = reg.get<Transform>(entity);

		target.camera.setCenter(transform.position);

		window.setView(target.camera);
	}
}
