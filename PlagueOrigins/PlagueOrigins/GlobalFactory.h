#pragma once
class GlobalFactory
{
public:
	dragonBones::SFMLFactory factory;
	static GlobalFactory& Instance();
private:
	sf::Texture heroAnim;
	sf::Texture dogAnim;
	sf::Texture bishopAnim;
	
	GlobalFactory();
	GlobalFactory(const GlobalFactory& root) = delete;
	GlobalFactory& operator = (const GlobalFactory&) = delete;
};
