#include <iostream>

#include "Entity.h"

const float ww::IEntity::UNIT_WIDTH = 64;
const float ww::IEntity::UNIT_HEIGHT = 64;

ww::Entity::Entity()
{
	_size = sf::Vector2f(UNIT_WIDTH, UNIT_HEIGHT);
	_enabled = true;
	_visible = true;
	_drawOrder = 0;
}

ww::Entity::~Entity()
{

}

void ww::Entity::update(const sf::Time & deltaTime)
{

}

void ww::Entity::draw(sf::RenderWindow & window)
{
	window.draw(_sprite);
}

bool ww::Entity::containsMouse(const sf::Vector2f & mousePos)
{
	return _sprite.getGlobalBounds().contains(mousePos);
}

bool ww::Entity::isClicked(const sf::Vector2f & mousePos)
{
	return containsMouse(mousePos) && _visible;
}

sf::Vector2f & ww::Entity::getPosition()
{
	return _pos;
}

void ww::Entity::setPosition(const sf::Vector2f & pos)
{
	this->_pos = pos;
	_sprite.setPosition(pos);
}

void ww::Entity::setPosition(float posX, float posY)
{
	this->_pos = sf::Vector2f(posX, posY);
	_sprite.setPosition(posX, posY);
}

sf::Vector2f & ww::Entity::getSize()
{
	return _size;
}

void ww::Entity::setSize(sf::Vector2f & size)
{
	this->_size = size;
}

void ww::Entity::setSize(float width, float height)
{
	this->_size = sf::Vector2f(width, height);
}

sf::Sprite & ww::Entity::getSprite()
{
	return _sprite;
}

bool ww::Entity::isEnabled()
{
	return _enabled;
}

void ww::Entity::setEnabled(bool enabled)
{
	this->_enabled = enabled;
}

bool ww::Entity::isVisible()
{
	return _visible;
}

void ww::Entity::setVisible(bool visible)
{
	this->_visible = visible;
}

int ww::Entity::getDrawOrder()
{
	return _drawOrder;
}

void ww::Entity::setDrawOrder(int drawOrder)
{
	this->_drawOrder = drawOrder;
}

