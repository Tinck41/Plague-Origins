#include "Button.h"

Button::Button()
{
}

Button::Button(
	const unsigned int x, 
	const unsigned int y, 
	const unsigned int width,
	const unsigned int height, 
	const unsigned int borderWidth,
	const std::string label
)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->state = ButtonState::DEFAULT;
	this->borderWidth = 3.0;
	this->borderColor = sf::Color(120, 120, 120);
	this->fontColor = sf::Color(25, 123, 23);
	this->bodyColor = sf::Color(32, 124, 0);
	this->hoverFontColor = sf::Color(120, 120, 120);

	this->body.setPosition(this->x, this->y);
	this->body.setFillColor(this->bodyColor);
	this->body.setSize(sf::Vector2f(this->width, this->height));
    this->body.setOutlineColor(this->borderColor);
	this->body.setOutlineThickness(this->borderWidth);

    this->label.setFont(CONFIG.MAIN_FONT);
	// this->label.setCharacterSize(25);
	this->label.setOrigin((int)(this->label.getLocalBounds().width / 2), (int)(this->label.getLocalBounds().height / 2));
	this->label.setPosition(this->x + (int)(this->width / 2), this->y + (int)(this->height / 2));
}

void Button::render(sf::RenderWindow& window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    if (mousePos.x > this->x && mousePos.y > this->y && mousePos.x < this->x + this->width && mousePos.y < this->y + this->height) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            this->state = ButtonState::CLICKED;
        }
        else if (state == ButtonState::CLICKED) {
            this->state = ButtonState::RELEASED;
        }
        else {
            this->state = ButtonState::HOVERED;
        }
    }
    else {
        this->state = ButtonState::DEFAULT;
    }

    this->body.setOutlineColor(this->borderColor);

    if (this->state == ButtonState::HOVERED) {
        this->body.setFillColor(this->borderColor);
        this->label.setFillColor(this->hoverFontColor);
    }
    else if (this->state == ButtonState::CLICKED) {
        this->body.setOutlineColor(this->bodyColor);
        this->body.setFillColor(this->borderColor);
        this->label.setFillColor(this->hoverFontColor);
    }
    else if (this->state == ButtonState::RELEASED) {
        this->body.setFillColor(this->borderColor);
        this->label.setFillColor(this->hoverFontColor);
    }
    else {
        this->body.setFillColor(this->bodyColor);
        this->label.setFillColor(this->fontColor);
    }

    window.draw(this->body);
    window.draw(this->label);
}

Button::~Button()
{
}