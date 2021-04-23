#pragma once
class ColliderComponent
{
public:
	ColliderComponent(b2Body* body, sf::Vector2f size);
	~ColliderComponent();

	b2Body* getBody() { return body; }

	void destroyBody();
	sf::Vector2f getPosition();
private:
	b2Body* body;
	sf::Vector2f size;
};

