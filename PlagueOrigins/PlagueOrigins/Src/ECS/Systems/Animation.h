#pragma once

#include "Src/ECS/Systems/IEcsUpdateSystem.h"

class Animation :
	public IEcsUpdateSystem
{
    void playAnimation();
	void playMovementAnimation();
	void playIdleAnimation();
	void playAttackAnimation();
	void playDeathAnimation();
	std::string setPostfix(std::string dir);

	void setAnimation(animationName newAnimation, sf::Vector2f newDirection);
	void setAnimation(animationName newAnimation);

	virtual void update(entt::registry& reg, const float& dt) override;
};