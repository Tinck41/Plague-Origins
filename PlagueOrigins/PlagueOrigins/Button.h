#pragma once

extern Config CONFIG;

enum ButtonState {
	DEFAULT,
	CLICKED,
	HOVERED,
	RELEASED
};

class Button
{
private:
	unsigned int x;
	unsigned int y;
	unsigned int width;
	unsigned int height;
	unsigned int borderWidth;
	sf::Text label;
	sf::Color borderColor;
	sf::Color fontColor;
	sf::Color hoverFontColor;
	sf::Color bodyColor;
	sf::RectangleShape body;

public:
	Button();
	Button(
		const unsigned int x,
		const unsigned int y,
		const unsigned int width,
		const unsigned int height,
		const unsigned int borderWidth,
		const std::string label
	);
	~Button();

	ButtonState state;

	void render(sf::RenderWindow&);
};

