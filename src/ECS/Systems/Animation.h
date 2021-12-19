#pragma once

#include "ECS/Systems/IUpdateSystem.h"
#include "ECS/Systems/IRenderSystem.h"
#include "ECS/Systems/IOnCreateSystem.h"

#include "ECS/Components.h"

class Animation :
	public IUpdateSystem,
	public IRenderSystem,
	public IOnCreateSystem
{
    void playAnimation(Animator& animator, Tag& tag, animationName name);
	void playMovementAnimation(Animator& animator, Tag& tag);
	void playIdleAnimation(Animator& animator, Tag& tag);
	void playAttackAnimation(Animator& animator, Tag& tag);
	void playDeathAnimation(Animator& animator, Tag& tag);
	void playDashAnimation(Animator& animator, Tag& tag);
	void playInteractionAnimation(Animator& animator, Tag& tag);
	std::string setPostfix(Tag& tag, std::string dir);

	void setAnimation(Animator& animator, Tag& tag);
	//void setAnimation(animationName newAnimation);

	virtual void onCreate(entt::registry& reg, tgui::GuiSFML& gui) override;
	virtual void update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt) override;
	virtual void render(entt::registry& reg, sf::RenderWindow& window, tgui::GuiSFML& gui) override;

};