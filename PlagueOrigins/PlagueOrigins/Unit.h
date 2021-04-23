#pragma once
#include "MovementComponent.h"
#include "AnimationComponent.h"
#include "ColliderComponent.h"
#include "CombatComponent.h"
#include "GlobalFactory.h"
#include "GameObjects.h"
#include "PlayerInventory.h"
#include "PlayerCharacteristics.h"

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
	int id;
	bool active;
	//combat
	float attackRange;
	float hitpoints;
	float damage;

	objects objectType;

	b2Body* body;

	PlayerInventory* inventory;
	PlayerCharacteristics* statsComponent;
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
	void createStatsComponent(std::string name);
	void createMovementComponent(b2Body* body, float speed);
	void createAnimationComponent(sf::RectangleShape& shape, dragonBones::SFMLFactory& zf, std::string prefix);
	void createColliderComponent(b2Body* body, sf::Vector2f size);
	void deleteColliderComponent();
	void createCombatComponent(sf::RectangleShape& shape, int id, objects objectType, float hitpoints, float damage, float attackRange, b2Body* body);
	//Getters
	virtual sf::RectangleShape getShape() { return shape; }
	CombatComponent* getCombatComponent() { return combatComponent; }
	PlayerInventory* getInventory() { return inventory; }
	PlayerCharacteristics* getStatsComponent() { return statsComponent; }
	int getId() { return id; }
	objects getObjectType() { return objectType; }

	void setActiveStatus(bool flag) { active = flag; }
	bool getActiveStatus() { return active; }

	virtual void update(const float& dt);

	virtual void render(sf::RenderWindow* window);

};



