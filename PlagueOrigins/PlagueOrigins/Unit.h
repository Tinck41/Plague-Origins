#pragma once
#include "MovementComponent.h"
#include "AnimationComponent.h"
#include "ColliderComponent.h"
#include "CombatComponent.h"
#include "GlobalFactory.h"
#include "GameObjects.h"
#include "PlayerInventory.h"

class Unit
{
private:
	//Game objects
	sf::RectangleShape shape;
	sf::Texture texture;
	sf::View view;
	GameObjects& gObjects;

	void initVariables();
	void spawnUnit();
protected:
	bool active;

	int id;
	objects objectType;

	b2Body* body;

	PlayerInventory* inventory;
	MovementComponent* movementComponent;
	AnimationComponent* animationComponent;
	ColliderComponent* colliderComponent;
	CombatComponent* combatComponent;
public:
	//Constructors/Destructors
	Unit();
	//virtual ~Unit() = 0;

	virtual bool operator==(const Unit* other) const
	{
		if (typeid(*this) != typeid(other))
			return false;

		return id == other->id;
	}

	//Functions
	void createMovementComponent(b2Body* body, float speed);
	void createAnimationComponent(sf::RectangleShape& shape, dragonBones::SFMLFactory& zf, std::string prefix);
	void createColliderComponent(b2Body* body, sf::Vector2f size);
	void deleteColliderComponent();
	void createCombatComponent(sf::RectangleShape& shape, float hitpoints, float damage);
	//Getters
	virtual sf::RectangleShape getShape() { return shape; }
	CombatComponent* getCombatComponent() { return combatComponent; }
	PlayerInventory* getInventory() { return inventory; }
	int getId() { return id; }
	objects getObjectType() { return objectType; }

	void setActiveStatus(bool flag) { active = flag; }
	bool getActiveStatus() { return active; }

	virtual void update(const float& dt);

	virtual void render(sf::RenderWindow* window);

};



