/** @file DragonBoy.cpp
 ** @author Piotr Krupa (piotrkrupa06@gmail.com)
 ** @license MIT License
 **/

#include <SFML/Graphics.hpp>

#include <dragonBones/SFMLFactory.h>
#include <dragonBones/SFMLArmatureDisplay.h>


int qmain()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "My window");
	window.setFramerateLimit(60);

	dragonBones::SFMLFactory factory;

	sf::Texture texture;

	//load
	texture.loadFromFile("./Assets/Animations/Hero/IdleRunEW/heroIdleRunEW_tex.png");

	factory.loadDragonBonesData("./Assets/Animations/Hero/IdleRunEW/heroIdleRunEW_ske.json");
	factory.loadTextureAtlasData("./Assets/Animations/Hero/IdleRunEW/heroIdleRunEW_tex.json", &texture);

	//dragonBones::SFMLArmatureDisplay* armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroIdle");

	//play
	/*armatureDisplay->getAnimation()->play("Idle");
	armatureDisplay->setPosition({ 512.f, 440.f });*/

	sf::Clock clock;

	while (window.isOpen())
	{
		float deltaTime = clock.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		factory.update(deltaTime);
		dragonBones::SFMLArmatureDisplay* armatureDisplay = new dragonBones::SFMLArmatureDisplay("ArmatureheroIdle");

		//play
		armatureDisplay->getAnimation()->play("Idle");
		armatureDisplay->setPosition({ 512.f, 440.f });
		window.clear();
		window.draw(*armatureDisplay);
		window.display();
	}
	
	return 0;
}
