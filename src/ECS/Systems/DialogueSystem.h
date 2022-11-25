#pragma once
#include "IRenderSystem.h"
#include "IUpdateSystem.h"
#include "IOnCreateSystem.h"
#include "ECS/Components.h"

class DialogueSystem :
	public IUpdateSystem,
	public IRenderSystem,
	public IOnCreateSystem
{
public:
	DialogueSystem();
	virtual void onCreate(entt::registry& reg, tgui::GuiSFML& gui) override;
	virtual void update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt) override;
	virtual void render(entt::registry& reg, sf::RenderWindow& window, tgui::GuiSFML& gui) override;
private:
	void dialogueSwitch(Dialogue& dialogue);
	void updateStats(entt::registry& reg, tgui::GuiSFML& gui, entt::entity player);

	void onUpgradeClick(entt::registry& reg, tgui::GuiSFML& gui);
	void onStatClick(entt::registry& reg, tgui::GuiSFML& gui, unsigned int stat);
	void onExitClick(entt::registry& reg, tgui::GuiSFML& gui);
};