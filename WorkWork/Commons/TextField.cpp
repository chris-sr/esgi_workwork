#include <iostream>

#include "TextField.h"

ww::TextField::TextField()
{

}

ww::TextField::~TextField()
{
	std::string text = _text.getString();
	std::cout << "TextField: " << text << " destroyed !" << std::endl;
}

void ww::TextField::load(sf::Texture & texture, sf::Font & font)
{
	_sprite.setTexture(texture);
	_sprite.setTextureRect(sf::IntRect(0, 64, 128, 64));
	_text.setFont(font);
}

void ww::TextField::update(const sf::Time & deltaTime)
{
	
}

void ww::TextField::draw(sf::RenderWindow & window)
{
	window.draw(_sprite);
	window.draw(_text);
}

bool ww::TextField::containsMouse(const sf::Vector2f & mousePos)
{
	return _sprite.getGlobalBounds().contains(mousePos) ? true : false;
}

bool ww::TextField::isClicked(const sf::Vector2f & mousePos)
{
	return containsMouse(mousePos) && _visible;
}

bool ww::TextField::isLetter(char letter)
{
	bool found = false;
	std::string letters = "abcdefghijklmnopqrstuvwxyz";
	letters.append("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	letters.append("ÈËÍÎ‡‚ÙˆÓÔÁ");
	letters.append("0123456789");
	
	for (int i = 0; i < letters.size(); i++)
	{
		char index = static_cast<char>(letters.at(i));
		if (index == letter)
		{
			found = true;
		}
	}
	return found;
}

void ww::TextField::centerText()
{
	if (_text.getGlobalBounds().width > 0 && _text.getGlobalBounds().height > 0)
	{
		_text.setPosition(_pos.x + ((_size.x - _text.getGlobalBounds().width) / 2), 
			_pos.y + ((_size.y - _text.getGlobalBounds().height) / 2) - 2);
	}
}

sf::Text & ww::TextField::getText()
{
	return _text;
}

