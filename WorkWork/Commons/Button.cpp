#include <iostream>

#include "Button.h"

ww::Button::Button()
{
    
}

ww::Button::Button(const sf::Vector2f & pos, const sf::Vector2f & size)
{

}

ww::Button::~Button()
{
	std::string text = _text.getString();
	std::cout << "Button " << text << " destroyed !" << std::endl;
}

void ww::Button::load(sf::Texture & texture, sf::Font & font)
{
	_sprite.setTexture(texture);
	_sprite.setTextureRect(sf::IntRect(0, 0, 128, 64));
	_text.setFont(font);
}

void ww::Button::update(const sf::Time & deltaTime)
{

}

void ww::Button::draw(sf::RenderWindow & window)
{
	window.draw(_sprite);
	window.draw(_text);
}

bool ww::Button::actionMouseEntered(const sf::Vector2f & mousePos, ww::Tooltip & tooltip)
{
    tooltip.setVisible(false);
    if (containsMouse(mousePos) && _visible)
    {
        tooltip.setVisible(true);
        tooltip.setPosition(mousePos.x - tooltip.getSize().x / 2,
                             mousePos.y - tooltip.getSize().y * 2);
        tooltip.centerText();
        return true;
    }
    return false;
}

void ww::Button::setText(const std::string & label, int labelSize, const sf::Color & labelColor)
{
	_text.setString(label);
	_text.setCharacterSize(labelSize);
	_text.setColor(labelColor);
	//Eviter d'utiliser la mÈthode bold, il vaut mieu utiliser la version bold du ttf !
	//buttonText.setStyle(sf::Text::Bold);
}

void ww::Button::centerText()
{
	if (_text.getGlobalBounds().width > 0 && _text.getGlobalBounds().height > 0)
	{
		_text.setPosition(_pos.x + ((_size.x - _text.getGlobalBounds().width) / 2), 
			_pos.y + ((_size.y - _text.getGlobalBounds().height) / 2) - 2);
	}
}

sf::Text & ww::Button::getText()
{
	return _text;
}

std::string & ww::Button::getTooltipLabel()
{
    return _tooltipLabel;
}

void ww::Button::setTooltipLabel(const std::string & tooltipLabel)
{
    this->_tooltipLabel = tooltipLabel;
}
