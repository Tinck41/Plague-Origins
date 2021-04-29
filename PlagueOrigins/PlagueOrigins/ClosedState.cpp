#include "stdafx.h"
//#include "stdafx.h"
//#include "ClosedState.h"
//
//ClosedState::ClosedState(InventoryComponent& owner) : owner(owner)
//{
//	stateMachine = owner.getStateMachine();
//}
//
//ClosedState::~ClosedState()
//{
//	stateMachine = NULL;
//	delete stateMachine;
//}
//
//void ClosedState::enter()
//{
//	owner.inventoryRenderer->closeAll();
//}
//
//void ClosedState::update(const float& dt)
//{
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape) && owner.escapeReleased)
//	{
//		owner.getStateMachine()->changeState(new MinimizedState(owner));
//	}
//	
//}
//
//void ClosedState::exit()
//{
//}
