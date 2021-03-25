#pragma once
class GlobalFactory
{
public:
	sf::Texture texture1;
	sf::Texture texture2;
	sf::Texture texture3;

	//dragonBones::SFMLFactory* zf;

	dragonBones::SFMLFactory& factorySet();

	GlobalFactory();
};
