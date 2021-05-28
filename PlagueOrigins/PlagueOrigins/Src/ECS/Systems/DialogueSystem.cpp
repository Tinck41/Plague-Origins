#include "stdafx.h"
#include "DialogueSystem.h"

DialogueSystem::DialogueSystem()
{
}

void DialogueSystem::onCreate(entt::registry& reg, tgui::GuiSFML& gui)
{
	gui.get<tgui::Panel>("mainDialoguePanel")->setVisible(false);
	gui.get<tgui::Panel>("upgradeStatsPanel")->setVisible(false);
	gui.get<tgui::Panel>("tradePanel")->setVisible(false);
}

void DialogueSystem::update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt)
{
	auto view = reg.view<Dialogue, PlayerInput, RigidBody>();
	for (auto entity : view)
	{
		Dialogue& dialogue = reg.get<Dialogue>(entity);
		PlayerInput& playerInput = reg.get<PlayerInput>(entity);
		RigidBody& rigidBody = reg.get<RigidBody>(entity);

		b2Fixture* interactionZone = rigidBody.body->GetFixtureList();
		while (interactionZone->GetUserData().pointer != INTERACTION_ZONE)
		{
			interactionZone = interactionZone->GetNext();
		}

		bool playerFound = false;

		for (b2ContactEdge* edge = interactionZone->GetBody()->GetContactList(); edge; edge = edge->next)
		{
			if (edge->contact->GetFixtureA()->GetUserData().pointer == FRIENDLY_NPC
					&& edge->contact->GetFixtureB()->GetUserData().pointer == INTERACTION_ZONE
				|| edge->contact->GetFixtureA()->GetUserData().pointer == INTERACTION_ZONE
					&& edge->contact->GetFixtureB()->GetUserData().pointer == FRIENDLY_NPC)
			{
				//entt::entity bishop = (entt::entity)edge->contact->GetFixtureB()->GetBody()->GetUserData().pointer;
				playerFound = true;
				if (playerInput.fReleased)
				{
					dialogue.isInteracting = true;
					reg.get<Dialogue>(dialogue.bishop).isInteracting = true;
					dialogueSwitch(dialogue);
				}

				if (playerInput.LMBreleased && dialogue.state == 1)
				{
					if (gui.get<tgui::Button>("upgradeStatsButton")->isMouseDown()) dialogue.state = 2;
					if (gui.get<tgui::Button>("tradeButton")->isMouseDown()) dialogue.state = 3;
					if (gui.get<tgui::Button>("exitButton")->isMouseDown()) dialogue.state = 0;
				}
			}
		}

		if (!playerFound)
		{
			dialogue.state = 0;
		}

		if (dialogue.state == 0)
		{
			dialogue.isInteracting = false;
			reg.get<Dialogue>(dialogue.bishop).isInteracting = false;
		}
	}
}

void DialogueSystem::render(entt::registry& reg, sf::RenderWindow& window, tgui::GuiSFML& gui)
{
	auto view = reg.view<Dialogue>();
	for (auto entity : view)
	{
		Dialogue& dialogue = reg.get<Dialogue>(entity);
		switch (dialogue.state)
		{
		case 0:
			gui.get<tgui::Panel>("mainDialoguePanel")->setVisible(false);
			gui.get<tgui::Panel>("upgradeStatsPanel")->setVisible(false);
			gui.get<tgui::Panel>("tradePanel")->setVisible(false);
			break;
		case 1:
			gui.get<tgui::Panel>("mainDialoguePanel")->setVisible(true);
			gui.get<tgui::Panel>("upgradeStatsPanel")->setVisible(false);
			gui.get<tgui::Panel>("tradePanel")->setVisible(false);
			break;
		case 2:
			gui.get<tgui::Panel>("mainDialoguePanel")->setVisible(false);
			gui.get<tgui::Panel>("upgradeStatsPanel")->setVisible(true);
			gui.get<tgui::Panel>("tradePanel")->setVisible(false);
		break;
		case 3:
			gui.get<tgui::Panel>("mainDialoguePanel")->setVisible(false);
			gui.get<tgui::Panel>("upgradeStatsPanel")->setVisible(false);
			gui.get<tgui::Panel>("tradePanel")->setVisible(true);
		break;
		default:
			break;
		}
	}
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
