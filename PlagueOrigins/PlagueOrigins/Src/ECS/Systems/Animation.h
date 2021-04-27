#pragma once

#include "Src/ECS/Systems/IEcsUpdateSystem.h"
#include "Src/ECS/Systems/IEcsRenderSystem.h"
#include "Src/ECS/Systems/IEcsOnCreateUpdate.h"

#include "Src/ECS/Components.h"

class Animation :
	public IEcsUpdateSystem,
	public IEcsRenderSystem,
	public IEcsOnCreateUpdate
{
    void playAnimation(Animator& animator, Tag& tag, animationName name);
	void playMovementAnimation(Animator& animator, Tag& tag);
	void playIdleAnimation(Animator& animator, Tag& tag);
	void playAttackAnimation(Animator& animator, Tag& tag);
	void playDeathAnimation(Animator& animator, Tag& tag);
	void playDashAnimation(Animator& animator, Tag& tag);
	std::string setPostfix(Tag& tag, std::string dir);

	void setAnimation(Animator& animator, Tag& tag);
	//void setAnimation(animationName newAnimation);

	virtual void onCreate(entt::registry& reg) override;
	virtual void update(entt::registry& reg, const float& dt) override;
	virtual void render(entt::registry& reg, sf::RenderWindow& window) override;

};