#include <iostream>

#include "DrawHandler.h"
#include "Entity.h"

ww::DrawHandler::DrawHandler()
{

}

ww::DrawHandler::~DrawHandler()
{
	std::cout << "DrawHandler destroyed !" << std::endl;
}

int ww::DrawHandler::getQueueSize()
{
	return _drawQueue.size();
}

void ww::DrawHandler::addInDrawQueue(ww::Entity* entity)
{
	if (entity->isVisible())
	{
		_drawQueue.push_back(entity);
	}
}

void ww::DrawHandler::sortDrawQueue()
{
	//TODO
}

void ww::DrawHandler::drawExecute(sf::RenderWindow & window)
{
	for (int i = 0; i < _drawQueue.size(); i++)
	{
		_drawQueue[i]->draw(window);
	}
}

void ww::DrawHandler::clearDrawQueue()
{
	_drawQueue.clear();
}