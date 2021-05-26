#include "stdafx.h"
#include "Input.h"

void Input::update(entt::registry& reg, tgui::GuiSFML& gui, const float& dt)
{
	auto view = reg.view<PlayerInput>();
	for (auto entity : view)
	{
		PlayerInput& input = reg.get<PlayerInput>(entity);
		movementInput(input);
		attackInput(input);
		menuInput(input);
		interactionInput(input);
	}
}

void Input::movementInput(PlayerInput& input)
{
	if (!input.canCheckForMovement)
	{
		resetMovementInput(input);
		return;
	}

	checkW(input);
	checkA(input);
	checkS(input);
	checkD(input);
	checkF(input);
	checkR(input);
	checkSpace(input);
}

void Input::attackInput(PlayerInput& input)
{
	if (!input.canCheckForAttack)
	{
		resetAttackInput(input);
		return;
	}

	checkLMB(input);
}

void Input::menuInput(PlayerInput& input)
{
	if (!input.canCheckForMenu)
	{
		resetMenuInput(input);
		return;
	}

	checkEsc(input);
}

void Input::interactionInput(PlayerInput& input)
{
}

void Input::resetMovementInput(PlayerInput& input)
{
	input.wPressed = false;
	input.wWasPressed = false;
	input.wReleased = false;

	input.aPressed = false;
	input.aWasPressed = false;
	input.aReleased = false;

	input.sPressed = false;
	input.sWasPressed = false;
	input.sReleased = false;

	input.dPressed = false;
	input.dWasPressed = false;
	input.dReleased = false;

	input.spacePressed = false;
	input.spaceWasPressed = false;
	input.spaceReleased = false;

}

void Input::resetAttackInput(PlayerInput& input)
{
	input.LMBpressed = false;
	input.LMBwasPressed = false;
	input.LMBreleased = false;
}

void Input::resetMenuInput(PlayerInput& input)
{
	input.escPressed = false;
	input.escWasPressed = false;
	input.escReleased = false;
}

void Input::resetInteractionInput(PlayerInput& input)
{
	input.fPressed = false;
	input.fWasPressed = false;
	input.fReleased = false;
}

void Input::checkW(PlayerInput& input)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && !input.wPressed)
	{
		input.wWasPressed = true;
		input.wPressed = true;
		input.wReleased = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		input.wWasPressed = false;
		input.wPressed = true;
		input.wReleased = false;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && input.wPressed)
	{
		input.wWasPressed = false;
		input.wPressed = false;
		input.wReleased = true;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		input.wWasPressed = false;
		input.wPressed = false;
		input.wReleased = false;
	}
}

void Input::checkA(PlayerInput& input)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && !input.aPressed)
	{
		input.aWasPressed = true;
		input.aPressed = true;
		input.aReleased = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		input.aWasPressed = false;
		input.aPressed = true;
		input.aReleased = false;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && input.aPressed)
	{
		input.aWasPressed = false;
		input.aPressed = false;
		input.aReleased = true;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		input.aWasPressed = false;
		input.aPressed = false;
		input.aReleased = false;
	}
}

void Input::checkS(PlayerInput& input)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && !input.sPressed)
	{
		input.sWasPressed = true;
		input.sPressed = true;
		input.sReleased = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		input.sWasPressed = false;
		input.sPressed = true;
		input.sReleased = false;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && input.sPressed)
	{
		input.sWasPressed = false;
		input.sPressed = false;
		input.sReleased = true;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		input.sWasPressed = false;
		input.sPressed = false;
		input.aReleased = false;
	}
}

void Input::checkD(PlayerInput& input)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && !input.dPressed)
	{
		input.dWasPressed = true;
		input.dPressed = true;
		input.dReleased = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		input.dWasPressed = false;
		input.dPressed = true;
		input.dReleased = false;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && input.dPressed)
	{
		input.dWasPressed = false;
		input.dPressed = false;
		input.dReleased = true;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		input.dWasPressed = false;
		input.dPressed = false;
		input.dReleased = false;
	}
}

void Input::checkF(PlayerInput& input)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F) && !input.fPressed)
	{
		input.fWasPressed = true;
		input.fPressed = true;
		input.fReleased = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F))
	{
		input.fWasPressed = false;
		input.fPressed = true;
		input.fReleased = false;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F) && input.fPressed)
	{
		input.fWasPressed = false;
		input.fPressed = false;
		input.fReleased = true;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F))
	{
		input.fWasPressed = false;
		input.fPressed = false;
		input.fReleased = false;
	}
}

void Input::checkR(PlayerInput& input)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R) && !input.rPressed)
	{
		input.rWasPressed = true;
		input.rPressed = true;
		input.rReleased = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
	{
		input.rWasPressed = false;
		input.rPressed = true;
		input.rReleased = false;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R) && input.rPressed)
	{
		input.rWasPressed = false;
		input.rPressed = false;
		input.rReleased = true;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
	{
		input.rWasPressed = false;
		input.rPressed = false;
		input.rReleased = false;
	}
}

void Input::checkSpace(PlayerInput& input)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && !input.spacePressed)
	{
		input.spaceWasPressed = true;
		input.spacePressed = true;
		input.spaceReleased = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		input.spaceWasPressed = false;
		input.spacePressed = true;
		input.spaceReleased = false;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && input.spacePressed)
	{
		input.spaceWasPressed = false;
		input.spacePressed = false;
		input.spaceReleased = true;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		input.spaceWasPressed = false;
		input.spacePressed = false;
		input.spaceReleased = false;
	}
}

void Input::checkLMB(PlayerInput& input)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && !input.LMBpressed)
	{
		input.LMBwasPressed = true;
		input.LMBpressed = true;
		input.LMBreleased = false;
	}
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		input.LMBwasPressed = false;
		input.LMBpressed = true;
		input.LMBreleased = false;
	}
	else if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && input.LMBpressed)
	{
		input.LMBwasPressed = false;
		input.LMBpressed = false;
		input.LMBreleased = true;
	}
	else if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		input.LMBwasPressed = false;
		input.LMBpressed = false;
		input.LMBreleased = false;
	}
}

void Input::checkEsc(PlayerInput& input)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape) && !input.escPressed)
	{
		input.escWasPressed = true;
		input.escPressed = true;
		input.escReleased = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		input.escWasPressed = false;
		input.escPressed = true;
		input.escReleased = false;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape) && input.escPressed)
	{
		input.escWasPressed = false;
		input.escPressed = false;
		input.escReleased = true;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		input.escWasPressed = false;
		input.escPressed = false;
		input.escReleased = false;
	}
}
