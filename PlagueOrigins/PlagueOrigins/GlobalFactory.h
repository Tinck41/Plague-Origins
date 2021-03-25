#pragma once
class GlobalFactory
{
public:
	dragonBones::SFMLFactory factory;
	static GlobalFactory& Instance();
private:
	sf::Texture heroAttackU;
	sf::Texture heroAttackR;
	sf::Texture heroAttackD;
	sf::Texture heroMoveU;
	sf::Texture heroMoveR;
	sf::Texture heroMoveD;
	sf::Texture dogAnim;
	
	GlobalFactory();
	GlobalFactory(const GlobalFactory& root) = delete;
	GlobalFactory& operator = (const GlobalFactory&) = delete;
};
