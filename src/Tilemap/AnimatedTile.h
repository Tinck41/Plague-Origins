#pragma once

class AnimatedTile
{
private:
	uint32_t id;
	sf::Vector2u position;
	
	float duration;
	sf::Time curDuration;

	std::vector<uint16_t> tilesId;
	size_t it;
public:
	AnimatedTile(uint16_t tileId, sf::Vector2u tilePosition, std::vector<uint16_t> tilesId, const float& duration = 0);
	~AnimatedTile();

	virtual void update(const float& dt);

	void changePosition(sf::Vector2u newPosition);

	uint32_t getId() { return id; }
	sf::Vector2u getPosition() { return position; }
};