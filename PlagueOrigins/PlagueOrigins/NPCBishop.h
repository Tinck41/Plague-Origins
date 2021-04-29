// #pragma once
// #include "Unit.h"
// #include "GlobalFactory.h"
// #include "LevelUpComponent.h"

// class NPCBishop :
//     public Unit
// {
// private:
// 	//Variables
// 	float scale;

// 	sf::RenderStates states;
// 	sf::RectangleShape shape;
// 	sf::Vector2f direction;

// 	GameObjects& gObjects;
// 	GlobalFactory& gFactory;
// 	dragonBones::SFMLFactory& factory;

// 	LevelUpComponent* levelUpComponent;

// 	void initVariables();
// 	void createHitbox(float x, float y);
// public:
// 	//Constructors/Destructors
// 	NPCBishop(float x, float y);
// 	~NPCBishop();
// 	//Functions
// 	void update(const float& dt);
// 	void render(sf::RenderWindow& target);
// 	//Getters
// 	sf::RectangleShape getShape() override { return shape; }
// 	sf::Vector2f getPosition() { return shape.getPosition(); }
// 	ColliderComponent getCollider() { return ColliderComponent(shape); }
// 	AnimationComponent* getAnimator() { return animationComponent; }
// 	MovementComponent* getMover() { return movementComponent; }
// };

