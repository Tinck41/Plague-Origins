#include "stdafx.h"
#include "Animation.h"

void Animation::playAnimation(Animator& animator, Tag& tag, animationName name)
{
	switch (name)
	{
	case(animationName::IDLE):
		playIdleAnimation(animator, tag);
		break;
	case(animationName::MOVE):
		playMovementAnimation(animator, tag);
		break;
	case(animationName::ATTACK):
		playAttackAnimation(animator, tag);
		break;
	case(animationName::DIE):
		playDeathAnimation(animator, tag);
		break;
	case(animationName::DASH):
		playDashAnimation(animator, tag);
		break;
	default:
		break;
	}
}

void Animation::playMovementAnimation(Animator& animator, Tag& tag)
{
	if (animator.currentDirection.y < 0.f)
	{
		animator.postfix = setPostfix(tag, "U");
		animator.armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature" + tag.name + animator.postfix);
	}
	else if (animator.currentDirection.y > 0.f)
	{
		animator.postfix = setPostfix(tag, "D");
		animator.armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature" + tag.name + animator.postfix);
	}
	if (animator.currentDirection.x > 0.f)
	{
		animator.postfix = setPostfix(tag, "R");
		animator.armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature" + tag.name + animator.postfix);
	}
	else if (animator.currentDirection.x < 0.f)
	{
		animator.postfix = setPostfix(tag, "R");
		animator.armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature" + tag.name + animator.postfix);
		animator.armatureDisplay->getArmature()->setFlipX(true);
	}

	animator.armatureDisplay->getAnimation()->fadeIn("Run", 0.3f, -1, 0, "hero", dragonBones::AnimationFadeOutMode::SameLayerAndGroup);
}

void Animation::playIdleAnimation(Animator& animator, Tag& tag)
{
	if (animator.currentDirection.y < 0.f)
	{
		animator.postfix = setPostfix(tag, "U");
		animator.armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature" + tag.name + animator.postfix);
	}
	else if (animator.currentDirection.y > 0.f)
	{
		animator.postfix = setPostfix(tag, "D");
		animator.armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature" + tag.name + animator.postfix);
	}
	if (animator.currentDirection.x > 0.f)
	{
		animator.postfix = setPostfix(tag, "R");
		animator.armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature" + tag.name + animator.postfix);
	}
	else if (animator.currentDirection.x < 0.f)
	{	
		animator.postfix = setPostfix(tag, "R");
		animator.armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature" + tag.name + animator.postfix);
		animator.armatureDisplay->getArmature()->setFlipX(true);
	}

	animator.armatureDisplay->getAnimation()->play("Idle");
}

void Animation::playAttackAnimation(Animator& animator, Tag& tag)
{
	if (animator.currentDirection.y < 0.f)
	{
		animator.postfix = setPostfix(tag, "U");
		animator.armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature" + tag.name + animator.postfix);
	}
	else if (animator.currentDirection.y > 0.f)
	{
		animator.postfix = setPostfix(tag, "D");
		animator.armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature" + tag.name + animator.postfix);
	}
	if (animator.currentDirection.x > 0.f)
	{
		animator.postfix = setPostfix(tag, "R");
		animator.armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature" + tag.name + animator.postfix);
	}
	else if (animator.currentDirection.x < 0.f)
	{
		animator.postfix = setPostfix(tag, "R");
		animator.armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature" + tag.name + animator.postfix);
		animator.armatureDisplay->getArmature()->setFlipX(true);
	}
	if (tag.name == "Hero")
	{
		//animator.armatureDisplay->getAnimation()->fadeIn("Attack", 0.2f, 1);
		animator.armatureDisplay->getAnimation()->play("Attack", 1);

	}
	else if (tag.name == "Dog")
	{
		animator.armatureDisplay->getAnimation()->play("Attack0", 1);
	}
}

void Animation::playDeathAnimation(Animator& animator, Tag& tag)
{
	if (animator.currentDirection.y < 0.f)
	{
		animator.postfix = setPostfix(tag, "U");
		animator.armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature" + tag.name + animator.postfix);
	}
	else if (animator.currentDirection.y > 0.f)
	{
		animator.postfix = setPostfix(tag, "D");
		animator.armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature" + tag.name + animator.postfix);
	}
	if (animator.currentDirection.x > 0.f)
	{
		animator.postfix = setPostfix(tag, "R");
		animator.armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature" + tag.name + animator.postfix);
	}
	else if (animator.currentDirection.x < 0.f)
	{
		animator.postfix = setPostfix(tag, "R");
		animator.armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature" + tag.name + animator.postfix);
		animator.armatureDisplay->getArmature()->setFlipX(true);
	}

	animator.armatureDisplay->getAnimation()->play("Die", 1);
	//animator.armatureDisplay->getAnimation()->fadeIn("Die", 1.f, 1);
}

void Animation::playDashAnimation(Animator& animator, Tag& tag)
{
	if (animator.currentDirection.y < 0.f)
	{
		animator.postfix = setPostfix(tag, "U");
		animator.armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature" + tag.name + animator.postfix);
	}
	else if (animator.currentDirection.y > 0.f)
	{
		animator.postfix = setPostfix(tag, "D");
		animator.armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature" + tag.name + animator.postfix);
	}
	if (animator.currentDirection.x > 0.f)
	{
		animator.postfix = setPostfix(tag, "R");
		animator.armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature" + tag.name + animator.postfix);
	}
	else if (animator.currentDirection.x < 0.f)
	{
		animator.postfix = setPostfix(tag, "R");
		animator.armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature" + tag.name + animator.postfix);
		animator.armatureDisplay->getArmature()->setFlipX(true);
	}

	animator.armatureDisplay->getAnimation()->play("Dash");
}

std::string Animation::setPostfix(Tag& tag, std::string dir)
{
	if (tag.name != "Bishop")
	{
		if (dir == "U")
			return dir;
		if (dir == "R")
			return dir;
		if (dir == "D")
			return dir;
	}
	else
		return "";
}

void Animation::setAnimation(Animator& animator, Tag& tag, animationName newAnimation, sf::Vector2f newDirection)
{

	if (animator.currentDirection != newDirection || animator.currentAnimation != newAnimation)
	{
		/*
			if 
				start run in opposite direction by x 
			or 
				start run upwards-downwards
			change animation
			else 
				don't
		*/
		if (animator.currentDirection.x != newDirection.x || animator.currentDirection.x == 0 && newDirection.x == 0 || animator.currentAnimation != newAnimation)
		{
			animator.currentDirection = newDirection;
			animator.currentAnimation = newAnimation;

			if (animator.armatureDisplay != nullptr)
			{
				animator.armatureDisplay->getArmature()->~Armature();
				delete animator.armatureDisplay;
				animator.armatureDisplay = NULL;
			}

			playAnimation(animator, tag, newAnimation);
		}
	}
}

void Animation::onCreate(entt::registry& reg)
{
	auto view = reg.view<Animator>();
	for (auto entity : view)
	{
		Animator& animator = reg.get<Animator>(entity);

		animator.states = animator.states.transform.scale(animator.scale, animator.scale);
		animator.armatureDisplay = nullptr;
	}
}

void Animation::update(entt::registry& reg, const float& dt)
{
	auto view = reg.view<Animator, Movement, Transform, Tag>();
	
	for (auto entity : view)
	{
		Animator& animator = reg.get<Animator>(entity);
		Movement& movement = reg.get<Movement>(entity);
		Transform& transform = reg.get<Transform>(entity);
		Tag& tag = reg.get<Tag>(entity);
		//Dash& dash = reg.get<Dash>(entity);

		if (movement.direction == sf::Vector2f(0.f, 0.f))
		{
			setAnimation(animator, tag, IDLE, animator.currentDirection);
		}
		else
		{
			setAnimation(animator, tag, MOVE, movement.direction);
		}

		animator.armatureDisplay->setPosition(sf::Vector2f(
			(1 / animator.scale) * (transform.position.x),
			(1 / animator.scale) * (transform.position.y)
		));
	}
}

void Animation::render(entt::registry& reg, sf::RenderWindow& window)
{
	auto view = reg.view<Animator>();
	for (auto entity : view)
	{
		Animator& animator = reg.get<Animator>(entity);
		window.draw(*animator.armatureDisplay, animator.states);
	}
}
