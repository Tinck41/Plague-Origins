#pragma once
#include "MovementComponent.h"
#include "AnimationComponent.h"
#include "ColliderComponent.h"
#include "CombatComponent.h"
#include "GlobalFactory.h"
#include "GameObjects.h"

class Unit
{
private:
	//Variables
	int speed;
	float dx;
	float dy;
	
	//Game objects
	sf::RectangleShape shape;
	sf::Texture texture;
	sf::View view;
	GameObjects& gObjects;

	void initVariables();
	void spawnUnit();
protected:
	MovementComponent* movementComponent;
	AnimationComponent* animationComponent;
	ColliderComponent* colliderComponent;
	CombatComponent* combatComponent;
public:
	//Constructors/Destructors
	Unit();
	//virtual ~Unit() = 0;
	int id;

	virtual bool operator==(const Unit* other) const
	{
		if (typeid(*this) != typeid(other))
			return false;

		return id == other->id;
	}

	//Functions
	void createMovementComponent(sf::RectangleShape& shape, int speed);
	void createAnimationComponent(sf::RectangleShape& shape, dragonBones::SFMLFactory& zf, std::string prefix);
	void createColliderComponent(sf::RectangleShape& shape);
	void createCombatComponent(sf::RectangleShape& shape, float hitpoints, float damage);

	virtual sf::RectangleShape getShape() { return shape; }
	CombatComponent* getCombatComponent() { return combatComponent; }

	virtual void update(const float& dt);

	virtual void render(sf::RenderWindow* window);

};



