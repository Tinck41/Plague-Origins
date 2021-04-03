#include "stdafx.h"
#include "CameraComponent.h"

CameraComponent::CameraComponent()
{
	camera = new sf::View();
	screenSize = sf::Vector2f(config.width(), config.height());
	reset();
}

void CameraComponent::setBounds(sf::Vector2u bounds)
{
	this->bounds = bounds;
}

void CameraComponent::update(sf::Vector2f center)
{
	updateSize();
	sf::Vector2f offset = sf::Vector2f(0, 0);
	sf::Vector2f size = camera->getSize();
	sf::Vector2f halfSize = sf::Vector2f(size.x / 2, size.y / 2);
	
	float distanceToLeft = center.x;
	float distanceToTop = center.y;
	float distanceToRight = bounds.x - center.x;
	float distanceToBottom = bounds.y - center.y;
	
	if (distanceToLeft < halfSize.x) {
		offset.x += halfSize.x - distanceToLeft;
	}
	if (distanceToTop < halfSize.y) {
		offset.y += halfSize.y - distanceToTop;
	}
	if (distanceToRight < halfSize.x) {
		offset.x -= halfSize.x - distanceToRight;
	}
	if (distanceToBottom < halfSize.y) {
		offset.y -= halfSize.y - distanceToBottom;
	}
	camera->setCenter(center.x + offset.x, center.y + offset.y);
}

void CameraComponent::setViewport(sf::RenderWindow& window)
{
	window.setView(*camera);
}

void CameraComponent::updateSize()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::XButton1))
	{
		camera->zoom(0.98);
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::XButton2)) 
	{
		camera->zoom(1.02);
	}
}

sf::Vector2f CameraComponent::getPosition()
{
	sf::Vector2f center = camera->getCenter();
	sf::Vector2f size = camera->getSize();
	return sf::Vector2f(center.x - size.x / 2, center.y - size.y / 2);
}

void CameraComponent::reset()
{
	camera->setSize(screenSize);
	camera->setCenter(screenSize.x / 2, screenSize.y / 2);
}

CameraComponent::~CameraComponent()
{
	delete camera;
}