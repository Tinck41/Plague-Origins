#include "stdafx.h"
#include "Camera.h"

void Camera::update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt)
{
	auto view = reg.view<CameraTarget, Transform>();
	for (auto entity : view)
	{
		CameraTarget& target = reg.get<CameraTarget>(entity);
		Transform& transform = reg.get<Transform>(entity);

		sf::Vector2f offset = sf::Vector2f(0, 0);
		sf::Vector2f size = target.camera.getSize();
		sf::Vector2f halfSize = sf::Vector2f(size.x / 2, size.y / 2);

		float distanceToLeft = transform.position.x;
		float distanceToTop = transform.position.y;
		float distanceToRight = target.bounds.x - transform.position.x;
		float distanceToBottom = target.bounds.y - transform.position.y;

		if (distanceToLeft < halfSize.x)
		{
			offset.x += halfSize.x - distanceToLeft;
		}
		if (distanceToTop < halfSize.y)
		{
			offset.y += halfSize.y - distanceToTop;
		}
		if (distanceToRight < halfSize.x)
		{
			offset.x -= halfSize.x - distanceToRight;
		}
		if (distanceToBottom < halfSize.y)
		{
			offset.y -= halfSize.y - distanceToBottom;
		}

		target.camera.setCenter(transform.position.x + offset.x, transform.position.y + offset.y);
	}
}

void Camera::render(entt::registry& reg, sf::RenderWindow& window, tgui::GuiSFML& gui)
{
	auto view = reg.view<CameraTarget>();
	for (auto entity : view)
	{
		CameraTarget& target = reg.get<CameraTarget>(entity);

		// Вызывает баг с отрисовкой, если рендерить view до полного рендера карты и сущностей на ней
		//window.setView(target.camera);
	}
}

