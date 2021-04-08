#pragma once
class ColliderComponent
{
public:
	ColliderComponent(b2Body* body);
	~ColliderComponent();

	b2Body* getBody() { return body; }

	sf::Vector2f getPosition();
private:
	b2Body* body;
};

