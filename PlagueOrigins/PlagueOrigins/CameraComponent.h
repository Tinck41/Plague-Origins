#pragma once

class CameraComponent
{
private:
	sf::View* camera;
	sf::Vector2f screenSize;
	sf::Vector2u bounds;

	void updateSize();
public:
	CameraComponent();
	~CameraComponent();

	sf::Vector2f getPosition();

	void update(sf::Vector2f center);
	void setViewport(sf::RenderWindow& window);
	void setBounds(sf::Vector2u bounds);
	void reset();
};

