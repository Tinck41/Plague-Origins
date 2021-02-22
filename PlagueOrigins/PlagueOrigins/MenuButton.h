#pragma once
#include "stdafx.h"
class MenuButton : public sf::Drawable, public sf::Transformable
{
public:
	MenuButton();
	~MenuButton();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

