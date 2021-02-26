/** @file DragonBoy.cpp
 ** @author Piotr Krupa (piotrkrupa06@gmail.com)
 ** @license MIT License
 **/

#include <SFML/Graphics.hpp>

#include <dragonBones/SFMLFactory.h>
#include <dragonBones/SFMLArmatureDisplay.h>


int qmain()
{
	sf::RenderWindow window(sf::VideoMode(1200, 800), "My window");
	window.setFramerateLimit(60);

	dragonBones::SFMLFactory factory;

	sf::Texture texture;
	sf::RenderStates states;
	states.transform.scale(0.2f, 0.2f);

	//load
	texture.loadFromFile("./CharacterAnimation03_tex.png");

	factory.loadDragonBonesData("./CharacterAnimation03_ske.json");
	factory.loadTextureAtlasData("./CharacterAnimation03_tex.json", &texture);

	dragonBones::SFMLArmatureDisplay* armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature");

	//play
	int count = 0;
	armatureDisplay->getAnimation()->play("Run");
	armatureDisplay->setPosition({ 1000.f, 2000.f });
	armatureDisplay->getEventDispatcher()->addDBEventListener(dragonBones::EventObject::LOOP_COMPLETE, [&](dragonBones::EventObject* event)
		{
			auto attackState = armatureDisplay->getAnimation()->getState("JumpUp");
			if (!attackState)
			{
				attackState = armatureDisplay->getAnimation()->fadeIn("JumpUp", 0.1f, 1, 1);
				attackState->resetToPose = false;
				attackState->autoFadeOutTime = 5.0f;
			}
			

		});
	armatureDisplay->getEventDispatcher()->addDBEventListener(dragonBones::EventObject::LOOP_COMPLETE, [&](dragonBones::EventObject* event)
		{
			auto dState = armatureDisplay->getAnimation()->getState("JumpDown");
			if (!dState)
			{
				dState = armatureDisplay->getAnimation()->fadeIn("JumpDown", 0.1f, 1, 1);
				dState->resetToPose = false;
				dState->autoFadeOutTime = 5.0f;
			}
		});
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

		window.clear();
		window.draw(*armatureDisplay, states);
		window.display();
	}
	
	return 0;
}
