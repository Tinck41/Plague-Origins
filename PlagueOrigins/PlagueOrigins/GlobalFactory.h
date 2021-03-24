#pragma once
static class GlobalFactory
{
public:
	sf::Texture texture;

	static dragonBones::SFMLFactory factory;

	GlobalFactory();
};

