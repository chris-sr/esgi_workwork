/* class header */
#include "AbstractView.h"

#include "Constants.h"
#include "DrawHandler.h"
#include "IEntity.h"

ww::AbstractView::AbstractView()
{
	_drawHandler = NULL;
	_enabled = false;
	_visible = true;
}

ww::AbstractView::~AbstractView()
{
	
}

void ww::AbstractView::init()
{

}

void ww::AbstractView::render(sf::RenderWindow & window)
{

}

bool ww::AbstractView::isVisible()
{
	return _visible;
}

void ww::AbstractView::setVisible(bool visible)
{
	this->_visible = visible;
}

bool ww::AbstractView::isEnabled()
{
	return _enabled;
}

void ww::AbstractView::setEnabled(bool enabled)
{
	this->_enabled = enabled;
}