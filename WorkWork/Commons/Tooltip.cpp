//
//  Tooltip.cpp
//  WorkWork
//
//  Created by Christophe Sin Ronia on 29/04/2014.
//  Copyright (c) 2014 Christophe Sin Ronia. All rights reserved.
//

#include <iostream>

#include "Tooltip.h"

ww::Tooltip::Tooltip()
{
    _visible = false;
}

ww::Tooltip::~Tooltip()
{
    
}

void ww::Tooltip::draw(sf::RenderWindow & window)
{
    if (_visible)
    {
        window.draw(_rect);
        window.draw(_text);
    }
}

void ww::Tooltip::centerText()
{
	if (_text.getGlobalBounds().width > 0 && _text.getGlobalBounds().height > 0)
	{
		_text.setPosition(_rect.getPosition().x + ((_rect.getSize().x - _text.getGlobalBounds().width) / 2),
                          _rect.getPosition().y + ((_rect.getSize().y - _text.getGlobalBounds().height) / 2) - 2);
	}
}

bool ww::Tooltip::isVisible()
{
    return _visible;
}

void ww::Tooltip::setVisible(bool visible)
{
    this->_visible = visible;
}

sf::RectangleShape & ww::Tooltip::getRect()
{
    return _rect;
}

sf::Text & ww::Tooltip::getText()
{
    return _text;
}
