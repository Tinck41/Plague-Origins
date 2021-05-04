#pragma once

class StaticTile
{
protected:
	uint32_t id;
	sf::Vector2u position;
public:
	StaticTile(uint32_t tileId, sf::Vector2u tilePosition);
	virtual ~StaticTile() {}

	virtual void update(const float& dt);

	uint32_t getId() { return id; }
	sf::Vector2u getPosition() { return position; }
};