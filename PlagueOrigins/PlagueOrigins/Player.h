#pragma once

#include "Unit.h"
#include "FiniteStateMachine.h"
#include "DirectionFinder.h"
//#include "PlayerStateHandler.h"

class PlayerIdleState;
class PlayerMoveState;

class Player : 
	public Unit
{
private: 
	//Variables
	sf::RenderStates states;
	int speed;
	float scale;

	InputBooleans inputBooleans;
	DirectionFinder directionFinder;
	//PlayerStateHandler playerStateHandler;

	FiniteStateMachine playerStateMachine;
	State* initState;

	//Game objects
	sf::RectangleShape shape;

	//dragonBones
	dragonBones::SFMLFactory factory;
	dragonBones::SFMLArmatureDisplay* armatureDisplay;

	void initVariables();
	void createHitbox(float x, float y);
public:
	//Constructors/Destructors
	Player(float x, float y);
	Player();
	~Player();

	Player(const Player&) = default;
	Player& operator=(const Player&) = default;

	//Functions
	void update(const float& dt);
	void render(sf::RenderWindow& target);

	// Getters
	sf::Vector2f getPosition() { return this->shape.getPosition(); }
	ColliderComponent getCollider() { return ColliderComponent(this->shape); }
	DirectionFinder getInput() { return this->directionFinder; }
	AnimationComponent* getAnimator() { return this->animationComponent; }

	// Setters
	void setArmature(dragonBones::SFMLArmatureDisplay* armatureDisplay) { this->armatureDisplay = armatureDisplay; }
};

//class PlayerMoveState :
//	public State
//{
//private:
//	FiniteStateMachine stateMachine;
//	Player& owner;
//public:
//	PlayerMoveState(FiniteStateMachine& stateMachine, Player& owner) :
//		owner(owner)
//	{
//		this->stateMachine = stateMachine;
//	}
//	~PlayerMoveState();
//
//	void enter() override
//	{
//		this->owner.getAnimator()->playAnimation(1, 4);
//	}
//	void execute() override
//	{
//		if (owner.getInput().getDirection() != sf::Vector2f(0, 0))
//			this->owner.getAnimator()->playAnimation(1, 4);
//		else
//			this->stateMachine.changeState(PLayerIdleState(this->stateMachine, this->owner));
//	}
//	void exit() override;
//};
//
//class PLayerIdleState :
//	public State
//{
//private:
//	FiniteStateMachine stateMachine;
//	Player& owner;
//public:
//	PLayerIdleState(FiniteStateMachine& stateMachine, Player& owner) :
//		owner(owner)
//	{
//		this->stateMachine = stateMachine;
//	}
//	~PLayerIdleState();
//
//	void enter() override
//	{
//		this->owner.getAnimator()->playAnimation(0, 2);
//	}
//	void execute() override
//	{
//		if (owner.getInput().getDirection() == sf::Vector2f(0, 0))
//			this->owner.getAnimator()->playAnimation(0, 2);
//		else
//			this->stateMachine.changeState(PlayerMoveState(this->stateMachine, this->owner));
//	}
//	void exit() override;
//};