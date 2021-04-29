// #include "stdafx.h"
// #include "UnfoldedState.h"

// UnfoldedState::UnfoldedState(InventoryComponent& owner) : owner(owner)
// {
// 	stateMachine = owner.getStateMachine();
// }

// UnfoldedState::~UnfoldedState()
// {
// 	stateMachine = NULL;
// 	delete stateMachine;
// }

// void UnfoldedState::enter()
// {
// 	owner.inventoryRenderer->openUnfolded();
// }

// void UnfoldedState::update(const float& dt)
// {
// 	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape) && owner.escapeReleased)
// 	{
// 		owner.getStateMachine()->changeState(new ClosedState(owner));
// 	}
// }

// void UnfoldedState::exit()
// {
// }
#include "stdafx.h"
