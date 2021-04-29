//#include "stdafx.h"
//#include "MinimizedState.h"
//
//MinimizedState::MinimizedState(InventoryComponent& owner) : owner(owner)
//{
//	stateMachine = owner.getStateMachine();
//}
//
//MinimizedState::~MinimizedState()
//{
//	stateMachine = NULL;
//	delete stateMachine;
//}
//
//void MinimizedState::enter()
//{
//	owner.inventoryRenderer->openMinimized();
//}
//
//void MinimizedState::update(const float& dt)
//{
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape) && owner.escapeReleased)
//	{
//		owner.getStateMachine()->changeState(new UnfoldedState(owner));
//	}
//}
//
//void MinimizedState::exit()
//{
//}
#include "stdafx.h"
