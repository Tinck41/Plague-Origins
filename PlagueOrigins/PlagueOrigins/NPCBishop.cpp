// #include "stdafx.h"
// #include "NPCBishop.h"

// NPCBishop::NPCBishop(float x, float y) :
// 	gFactory(GlobalFactory::Instance()), factory(gFactory.factory), gObjects(GameObjects::Instance())
// {
// 	gObjects.registerObject(this, objects::merchants);
// 	id = 2;

// 	initVariables();
// 	createHitbox(x, y);

// 	createAnimationComponent(shape, factory, "Bishop");
// 	animationComponent->initArmature(sf::Vector2f(x, y));
// 		states.transform.scale(scale, scale);
// 		animationComponent->setAnimation(animationName::IDLE);

// 	createColliderComponent(shape);

// 	levelUpComponent = new LevelUpComponent(shape);
// }

// NPCBishop::~NPCBishop()
// {
// }

// void NPCBishop::initVariables()
// {
// 	scale = config.bishopScale;
// 	direction = { .0f, 1.0f };
// }

// void NPCBishop::createHitbox(float x, float y)
// {
// 	shape.setPosition(x, y);
// 	shape.setSize(sf::Vector2f(config.bishopHitboxWidth, config.bishopHitboxHeight));
// 	shape.setFillColor(sf::Color::Red);
// }

// void NPCBishop::update(const float& dt)
// {
// 	//interaction
// 	levelUpComponent->interact();
// 	//animation
// 	animationComponent->setAnimation(animationName::IDLE);
// 	animationComponent->getArmatureDisplay()->setPosition(sf::Vector2f((1 / scale) * (shape.getPosition().x + colliderComponent->getHalfSize().x), (1 / scale) * (shape.getPosition().y + colliderComponent->getHalfSize().y)));
// 	//animationComponent->updateFactory(dt);
// }

// void NPCBishop::render(sf::RenderWindow& target)
// {
// 	target.draw(levelUpComponent->getInteractionTrigger());
// 	target.draw(shape);
// 	target.draw(*animationComponent->getArmatureDisplay(), states);
// }

#include "stdafx.h"
