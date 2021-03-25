#pragma once
class GlobalFactory
{
public:
	dragonBones::SFMLFactory factory;
	dragonBones::SFMLFactory& factorySet();
	static GlobalFactory& Instance();
protected:
	sf::Texture texture1;
	sf::Texture texture2;
	sf::Texture texture3;
private:
	GlobalFactory();
	GlobalFactory(const GlobalFactory& root) = delete;
	GlobalFactory& operator = (const GlobalFactory&) = delete;
};
