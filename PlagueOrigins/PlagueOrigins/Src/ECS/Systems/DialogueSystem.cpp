#include "stdafx.h"
#include "DialogueSystem.h"
#include "StatsSystem.h"

DialogueSystem::DialogueSystem()
{
}

void DialogueSystem::onCreate(entt::registry& reg, tgui::GuiSFML& gui)
{
	gui.get<tgui::Panel>("mainDialoguePanel")->setVisible(false);
	gui.get<tgui::Panel>("upgradeStatsPanel")->setVisible(false);

	auto upgradeButton = gui.get<tgui::Panel>("mainDialoguePanel")->get<tgui::Button>("upgradeStatsButton");
	auto exitButton = gui.get<tgui::Panel>("mainDialoguePanel")->get<tgui::Button>("exitButton");

	auto VITbutton = gui.get<tgui::Panel>("upgradeStatsPanel")->get<tgui::Button>("VITbutton");
	auto STRbutton = gui.get<tgui::Panel>("upgradeStatsPanel")->get<tgui::Button>("STRbutton");
	auto ENDbutton = gui.get<tgui::Panel>("upgradeStatsPanel")->get<tgui::Button>("ENDbutton");
	auto AGIbutton = gui.get<tgui::Panel>("upgradeStatsPanel")->get<tgui::Button>("AGIbutton");
	auto INTbutton = gui.get<tgui::Panel>("upgradeStatsPanel")->get<tgui::Button>("INTbutton");

	upgradeButton->onMouseRelease(&DialogueSystem::onUpgradeClick, this, std::ref(reg), std::ref(gui));
	exitButton->onMouseRelease(&DialogueSystem::onExitClick, this, std::ref(reg), std::ref(gui));
	VITbutton->onMouseRelease(&DialogueSystem::onStatClick, this, std::ref(reg), std::ref(gui), VIT);
	STRbutton->onMouseRelease(&DialogueSystem::onStatClick, this, std::ref(reg), std::ref(gui), STR);
	ENDbutton->onMouseRelease(&DialogueSystem::onStatClick, this, std::ref(reg), std::ref(gui), END);
	AGIbutton->onMouseRelease(&DialogueSystem::onStatClick, this, std::ref(reg), std::ref(gui), AGI);
	INTbutton->onMouseRelease(&DialogueSystem::onStatClick, this, std::ref(reg), std::ref(gui), INTT);

}

void DialogueSystem::update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt)
{
	auto view = reg.view<Dialogue, PlayerInput, RigidBody, Stats>();
	for (auto entity : view)
	{
		Dialogue& dialogue = reg.get<Dialogue>(entity);
		PlayerInput& playerInput = reg.get<PlayerInput>(entity);
		RigidBody& rigidBody = reg.get<RigidBody>(entity);

		//if (dialogue.state == 2)
		//{
		//	updateStats(reg, gui, entity);
		//}

		b2Fixture* interactionZone = rigidBody.body->GetFixtureList();
		while (interactionZone->GetUserData().pointer != INTERACTION_ZONE)
		{
			interactionZone = interactionZone->GetNext();
		}

		for (b2ContactEdge* edge = interactionZone->GetBody()->GetContactList(); edge; edge = edge->next)
		{
			if (edge->contact->GetFixtureA()->GetUserData().pointer == FRIENDLY_NPC
					&& edge->contact->GetFixtureB()->GetUserData().pointer == INTERACTION_ZONE
				|| edge->contact->GetFixtureA()->GetUserData().pointer == INTERACTION_ZONE
					&& edge->contact->GetFixtureB()->GetUserData().pointer == FRIENDLY_NPC)
			{
				if (playerInput.fReleased)
				{
					dialogue.isInteracting = true;
					reg.get<Dialogue>(dialogue.bishop1).isInteracting = true;
					reg.get<Dialogue>(dialogue.bishop2).isInteracting = true;
					gui.get<tgui::Panel>("mainDialoguePanel")->setVisible(true);
				}
			}
		}

		if (!gui.get<tgui::Panel>("mainDialoguePanel")->isVisible())
		{
			dialogue.isInteracting = false;
			reg.get<Dialogue>(dialogue.bishop1).isInteracting = false;
			reg.get<Dialogue>(dialogue.bishop2).isInteracting = false;
		}
	}
}

void DialogueSystem::render(entt::registry& reg, sf::RenderWindow& window, tgui::GuiSFML& gui)
{

}

void DialogueSystem::dialogueSwitch(Dialogue& dialogue)
{
	if (dialogue.state == 0)
	{
		dialogue.state = 1;
	}
	else if (dialogue.state > 1)
	{
		dialogue.state = 1;
	}
	else if (dialogue.state == 1)
	{
		dialogue.state = 0;
	}
}

void DialogueSystem::updateStats(entt::registry& reg, tgui::GuiSFML& gui, entt::entity player)
{
	StatsSystem statsSystem;
	Inventory& essence = reg.get<Inventory>(player);
	Stats& stats = reg.get<Stats>(player);
	Health& health = reg.get<Health>(player);
	Attack& attack = reg.get<Attack>(player);
	Stamina& stamina = reg.get<Stamina>(player);
	Dash& dash = reg.get<Dash>(player);

	gui.get<tgui::Label>("EScur")->setText((tgui::String)essence.essence);
	gui.get<tgui::Label>("VITcur")->setText((tgui::String)stats.VIT);
	gui.get<tgui::Label>("STRcur")->setText((tgui::String)stats.STR);
	gui.get<tgui::Label>("ENDcur")->setText((tgui::String)stats.END);
	gui.get<tgui::Label>("AGIcur")->setText((tgui::String)stats.AGI);
	gui.get<tgui::Label>("INTcur")->setText((tgui::String)stats.INT);

	if (essence.essence >= stats.upgradeCost)
	{
		gui.get<tgui::Label>("ESnew")->setText((tgui::String)(essence.essence - stats.upgradeCost));
	}
	else
	{
		gui.get<tgui::Label>("ESnew")->setText("Not enough.");
	}
	gui.get<tgui::Label>("VITnew")->setText((tgui::String)(stats.VIT+1));
	gui.get<tgui::Label>("STRnew")->setText((tgui::String)(stats.STR+1));
	gui.get<tgui::Label>("ENDnew")->setText((tgui::String)(stats.END+1));
	gui.get<tgui::Label>("AGInew")->setText((tgui::String)(stats.AGI+1));
	gui.get<tgui::Label>("INTnew")->setText((tgui::String)(stats.INT+1));

	gui.get<tgui::Label>("HPcur")->setText((tgui::String)health.maxHealth);
	gui.get<tgui::Label>("DMGcur")->setText((tgui::String)attack.damage);
	gui.get<tgui::Label>("STMcur")->setText((tgui::String)stamina.maxStamina);
	gui.get<tgui::Label>("DCDcur")->setText((tgui::String)dash.cooldownTime);

	gui.get<tgui::Label>("HPnew")->setText((tgui::String)statsSystem.newHp(stats, 1));
	gui.get<tgui::Label>("DMGnew")->setText((tgui::String)statsSystem.newDamage(stats, 1));
	gui.get<tgui::Label>("STMnew")->setText((tgui::String)statsSystem.newStamina(stats, 1));
	gui.get<tgui::Label>("DCDnew")->setText((tgui::String)statsSystem.newDashCD(stats, 1));
}

void DialogueSystem::onUpgradeClick(entt::registry& reg, tgui::GuiSFML& gui)
{
	auto view = reg.view<Player>();
	for (auto& entity : view)
	{
		bool isVisible = gui.get<tgui::Panel>("upgradeStatsPanel")->isVisible();

		gui.get<tgui::Panel>("upgradeStatsPanel")->setVisible(!isVisible);

		updateStats(reg, gui, entity);
	}
}

void DialogueSystem::onExitClick(entt::registry& reg, tgui::GuiSFML& gui)
{
	bool isVisible = gui.get<tgui::Panel>("mainDialoguePanel")->isVisible();
	gui.get<tgui::Panel>("mainDialoguePanel")->setVisible(!isVisible);
}

void DialogueSystem::onStatClick(entt::registry& reg, tgui::GuiSFML& gui, unsigned int stat)
{
	auto view = reg.view<Player>();
	for (auto& entity : view)
	{
		StatsSystem statsSystem;
		Stats& stats = reg.get<Stats>(entity);
		Inventory& essence = reg.get<Inventory>(entity);
		statsSystem.increaseChar(reg, entity, stats, essence, (charName)stat);
		updateStats(reg, gui, entity);
	}
}
