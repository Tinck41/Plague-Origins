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
	case(animationName::INTERACT):
		playInteractionAnimation(animator, tag);
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
		animator.currentAnimationDuration = sf::seconds(armatureDisplay->getAnimation()->getState("Run")->_duration).asMilliseconds();
		animator.currentAnimationDurationLeft = sf::seconds(0.f).asMilliseconds();
		armatureDisplay = nullptr;
		delete armatureDisplay;
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
		animator.currentAnimationDuration = sf::seconds(armatureDisplay->getAnimation()->getState("Idle")->_duration).asMilliseconds();
		animator.currentAnimationDurationLeft = sf::seconds(0.f).asMilliseconds();
		armatureDisplay = nullptr;
		delete armatureDisplay;
	}
}

void Animation::playAttackAnimation(Animator& animator, Tag& tag)
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
		if (armatureDisplay != nullptr)
		{
			animator.armatureDisplay = armatureDisplay;
			if (tag.name == "Hero")
			{
				animator.armatureDisplay->getAnimation()->play("Attack", 1);
				animator.currentAnimationDuration = sf::seconds(armatureDisplay->getAnimation()->getState("Attack")->_duration).asMilliseconds();
			}
			else if (tag.name == "Dog" || tag.name == "Boss")
			{
				animator.armatureDisplay->getAnimation()->play("Attack0", 1);
				animator.currentAnimationDuration = sf::seconds(armatureDisplay->getAnimation()->getState("Attack0")->_duration).asMilliseconds();
			}
			animator.currentAnimationDurationLeft = sf::seconds(0.f).asMilliseconds();
			armatureDisplay = nullptr;
			delete armatureDisplay;
		}
	}
}

void Animation::playDeathAnimation(Animator& animator, Tag& tag)
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
		animator.armatureDisplay->getAnimation()->play("Die", 1);
		animator.currentAnimationDuration = sf::seconds(armatureDisplay->getAnimation()->getState("Die")->_duration).asMilliseconds();
		animator.currentAnimationDurationLeft = sf::seconds(0.f).asMilliseconds();
		armatureDisplay = nullptr;
		delete armatureDisplay;
	}
}

void Animation::playDashAnimation(Animator& animator, Tag& tag)
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
		animator.armatureDisplay->getAnimation()->play("Dash");
		animator.currentAnimationDuration = sf::seconds(armatureDisplay->getAnimation()->getState("Dash")->_duration).asMilliseconds();
		animator.currentAnimationDurationLeft = sf::seconds(0.f).asMilliseconds();
		armatureDisplay = nullptr;
		delete armatureDisplay;
	}
}

void Animation::playInteractionAnimation(Animator& animator, Tag& tag)
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
		animator.armatureDisplay->getAnimation()->play("LevelUp");
		animator.currentAnimationDuration = sf::seconds(armatureDisplay->getAnimation()->getState("LevelUp")->_duration).asMilliseconds();
		animator.currentAnimationDurationLeft = sf::seconds(0.f).asMilliseconds();
		armatureDisplay = nullptr;
		delete armatureDisplay;
	}
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
		return "";
	}
	else
		return "";
}

void Animation::setAnimation(Animator& animator, Tag& tag)
{

	if (animator.previousFaceDirection != animator.currentFaceDirection || animator.previousAnimation != animator.currentAnimation)
	{
		if (animator.previousFaceDirection.x >= 0 && animator.currentFaceDirection.x <= 0
			|| animator.previousFaceDirection.x <= 0 && animator.currentFaceDirection.x >= 0
			|| animator.previousAnimation != animator.currentAnimation
			)
		{
			if (animator.armatureDisplay != nullptr)
			{
				animator.armatureDisplay->getArmature()->~Armature();
				delete animator.armatureDisplay;
				animator.armatureDisplay = nullptr;
			}

			playAnimation(animator, tag, animator.currentAnimation);

			animator.previousFaceDirection = animator.currentFaceDirection;
			animator.previousAnimation = animator.currentAnimation;
		}
		
	}
}

void Animation::onCreate(entt::registry& reg, tgui::GuiSFML& gui)
{
	auto view = reg.view<Animator>();
	for (auto entity : view)
	{
		Animator& animator = reg.get<Animator>(entity);

		animator.states = animator.states.transform.scale(animator.scale, animator.scale);
		animator.armatureDisplay = nullptr;
	}
}

void Animation::update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt)
{
	auto view = reg.view<Animator, Transform, Tag>();
	
	for (auto entity : view)
	{
		Animator& animator = reg.get<Animator>(entity);
		Transform& transform = reg.get<Transform>(entity);
		Tag& tag = reg.get<Tag>(entity);

		setAnimation(animator, tag);

		if (animator.armatureDisplay->getAnimation()->isCompleted())
		{
			animator.currentAnimationDurationLeft = sf::seconds(0).asMilliseconds();
		}
		else
		{
			animator.currentAnimationDurationLeft += sf::seconds(dt).asMilliseconds();
		}

		if (animator.armatureDisplay != nullptr)
		{
			animator.armatureDisplay->setPosition((1 / animator.scale) * transform.position);
		}
	}
}

void Animation::render(entt::registry& reg, sf::RenderWindow& window, tgui::GuiSFML& gui)
{
	std::list<Animator> sortedObjects;
	float playerYPosition = 0;

	auto playerView = reg.view<PlayerInput, Animator, Transform, RigidBody>();
	for (auto entity : playerView)
	{
		Transform& transform = reg.get<Transform>(entity);
		RigidBody& rigidBody = reg.get<RigidBody>(entity);
		Animator& animator = reg.get<Animator>(entity);

		playerYPosition = transform.position.y + rigidBody.size.y / 2.f;
		sortedObjects.push_back(animator);
	}

	auto view = reg.view<Animator, Transform, RigidBody, NPC>();
	for (auto entity : view)
	{
		RigidBody& rigidBody = reg.get<RigidBody>(entity);
		Animator& animator = reg.get<Animator>(entity);
		Transform& transform = reg.get<Transform>(entity);

		float entityYPosition = transform.position.y + rigidBody.size.y / 2.f;

		if (playerYPosition > entityYPosition)
		{
			sortedObjects.emplace_front(animator);
		}
		else
		{
			sortedObjects.emplace_back(animator);
		}
	}

	for (auto i = sortedObjects.begin(); i != sortedObjects.end(); i++)
	{
		if (i->armatureDisplay != nullptr)
		{
			window.draw(*i->armatureDisplay, i->states);
		}
	}
}
