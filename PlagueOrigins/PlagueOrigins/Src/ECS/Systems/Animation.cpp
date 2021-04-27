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
	dragonBones::SFMLArmatureDisplay* armatureDisplay = nullptr;

	if (animator.currentFaceDirection.y < 0.f)
	{
		animator.postfix = setPostfix(tag, "U");
		armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature" + tag.name + animator.postfix);
	}
	else if (animator.currentFaceDirection.y > 0.f)
	{
		animator.postfix = setPostfix(tag, "D");
		armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature" + tag.name + animator.postfix);
	}
	if (animator.currentFaceDirection.x > 0.f)
	{
		animator.postfix = setPostfix(tag, "R");
		armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature" + tag.name + animator.postfix);
	}
	else if (animator.currentFaceDirection.x < 0.f)
	{
		animator.postfix = setPostfix(tag, "R");
		armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature" + tag.name + animator.postfix);
		armatureDisplay->getArmature()->setFlipX(true);
	}

	if (armatureDisplay != nullptr)
	{
		animator.armatureDisplay = armatureDisplay;
		animator.armatureDisplay->getAnimation()->play("Run");
		//animator.armatureDisplay->getAnimation()->fadeIn("Run", 0.3f, -1, 0, "hero", dragonBones::AnimationFadeOutMode::SameLayerAndGroup);
	}
}

void Animation::playIdleAnimation(Animator& animator, Tag& tag)
{
	dragonBones::SFMLArmatureDisplay* armatureDisplay = nullptr;

	if (animator.currentFaceDirection.y < 0.f)
	{
		animator.postfix = setPostfix(tag, "U");
		armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature" + tag.name + animator.postfix);
	}
	else if (animator.currentFaceDirection.y > 0.f)
	{
		animator.postfix = setPostfix(tag, "D");
		armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature" + tag.name + animator.postfix);
	}
	if (animator.currentFaceDirection.x > 0.f)
	{
		animator.postfix = setPostfix(tag, "R");
		armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature" + tag.name + animator.postfix);
	}
	else if (animator.currentFaceDirection.x < 0.f)
	{	
		animator.postfix = setPostfix(tag, "R");
		armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature" + tag.name + animator.postfix);
		armatureDisplay->getArmature()->setFlipX(true);
	}

	if (armatureDisplay != nullptr)
	{
		animator.armatureDisplay = armatureDisplay;
		animator.armatureDisplay->getAnimation()->play("Idle");
	}
}

void Animation::playAttackAnimation(Animator& animator, Tag& tag)
{
	if (animator.currentFaceDirection.y < 0.f)
	{
		animator.postfix = setPostfix(tag, "U");
		animator.armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature" + tag.name + animator.postfix);
	}
	else if (animator.currentFaceDirection.y > 0.f)
	{
		animator.postfix = setPostfix(tag, "D");
		animator.armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature" + tag.name + animator.postfix);
	}
	if (animator.currentFaceDirection.x > 0.f)
	{
		animator.postfix = setPostfix(tag, "R");
		animator.armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature" + tag.name + animator.postfix);
	}
	else if (animator.currentFaceDirection.x < 0.f)
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
	if (animator.currentFaceDirection.y < 0.f)
	{
		animator.postfix = setPostfix(tag, "U");
		animator.armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature" + tag.name + animator.postfix);
	}
	else if (animator.currentFaceDirection.y > 0.f)
	{
		animator.postfix = setPostfix(tag, "D");
		animator.armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature" + tag.name + animator.postfix);
	}
	if (animator.currentFaceDirection.x > 0.f)
	{
		animator.postfix = setPostfix(tag, "R");
		animator.armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature" + tag.name + animator.postfix);
	}
	else if (animator.currentFaceDirection.x < 0.f)
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
	if (animator.currentFaceDirection.y < 0.f)
	{
		animator.postfix = setPostfix(tag, "U");
		animator.armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature" + tag.name + animator.postfix);
	}
	else if (animator.currentFaceDirection.y > 0.f)
	{
		animator.postfix = setPostfix(tag, "D");
		animator.armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature" + tag.name + animator.postfix);
	}
	if (animator.currentFaceDirection.x > 0.f)
	{
		animator.postfix = setPostfix(tag, "R");
		animator.armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature" + tag.name + animator.postfix);
	}
	else if (animator.currentFaceDirection.x < 0.f)
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

void Animation::setAnimation(Animator& animator, Tag& tag)
{

	if (animator.previousFaceDirection != animator.currentFaceDirection || animator.previousAnimation != animator.currentAnimation)
	{
		if (animator.armatureDisplay != nullptr)
		{
			animator.armatureDisplay->getArmature()->~Armature();
			delete animator.armatureDisplay;
			animator.armatureDisplay = NULL;
		}

		playAnimation(animator, tag, animator.currentAnimation);
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

		setAnimation(animator, tag);

		if (animator.armatureDisplay != nullptr)
		{
			animator.armatureDisplay->setPosition(sf::Vector2f(
				(1 / animator.scale) * (transform.position.x),
				(1 / animator.scale) * (transform.position.y)
			));
		}
	}
}

void Animation::render(entt::registry& reg, sf::RenderWindow& window)
{
	auto view = reg.view<Animator>();
	for (auto entity : view)
	{
		Animator& animator = reg.get<Animator>(entity);

		if (animator.armatureDisplay != nullptr)
		{
			window.draw(*animator.armatureDisplay, animator.states);
		}
	}
}
