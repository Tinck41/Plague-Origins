#pragma once
class ColliderComponent
{
private:
	sf::RectangleShape& body;
public:
	ColliderComponent(sf::RectangleShape& body);
	~ColliderComponent();

	void move(float dx, float dy) { this->body.move(dx, dy); }

	bool checkCollision(ColliderComponent other, float push);

	sf::Vector2f getPosition() { return this->body.getPosition(); }
	sf::Vector2f getHalfSize() { return this->body.getSize() / 2.0f; }
};

