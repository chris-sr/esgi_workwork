#include <iostream>

#include "DebugMode.h"

#include "Constants.h"
#include "Simulation.h"
#include "Settings.h"
#include "IScene.h"
#include "ResourceHandler.h"
#include "DrawHandler.h"

#include "IEntity.h"

ww::DebugMode::DebugMode(ww::Simulation* simulation)
{
	this->_simulation = simulation;
	this->_resourceHandler = simulation->getResourceHandler();

	_showTextFPS = false;
	_showGrid = false;
	_showTextEntityDraw = false;
	_showTextVideoMode = false;
}

ww::DebugMode::~DebugMode()
{
	std::cout << "DebugMode destroyed !" << std::endl;
}

bool ww::DebugMode::loadFont(const std::string & fontPath)
{
	if (!_resourceHandler->loadFont(fontPath))
	{
		std::cout << "DebugMode:Error loading font file : " << fontPath << std::endl;
		return false;
	}
	_text.setFont(_resourceHandler->getFontMap()[fontPath]);
	return true;
}

void ww::DebugMode::renderDebug(sf::RenderWindow & window)
{
	drawTextFPS(window, "FPS ", 0, 0, 12, sf::Color::White);
	drawGrid(window);
	drawTextEntityDraw(window, "EntityDraw ", 0, 15, 12, sf::Color::White);
	drawTextVideoMode(window, "VideoMode ", 0, 30, 12, sf::Color::White);
}

void ww::DebugMode::drawTextFPS(sf::RenderWindow & window, const std::string & msg, float posX, float posY,
                                const int charSize, const sf::Color & color)
{
	if (_showTextFPS)
	{	
		_ss.str("");
		_ss << msg << _simulation->getFPS();
		_text.setString(_ss.str());
		_text.setPosition(posX, posY);
		_text.setCharacterSize(charSize);
		_text.setColor(color);
		window.draw(_text);
	}
}

void ww::DebugMode::drawGrid(sf::RenderWindow & window)
{
	if (_showGrid)
	{
		sf::VertexArray line(sf::Lines, 2);

		line[0].color = sf::Color::Red;
		line[1].color = sf::Color::Red;

		for (int i = 0; i < _gridSize.x / IEntity::UNIT_WIDTH; i++)
		{
			line[0].position = sf::Vector2f(i * IEntity::UNIT_WIDTH, 0);
			line[1].position = sf::Vector2f(i * IEntity::UNIT_WIDTH, _gridSize.y);
			window.draw(line);
		}

		for (int i = 0; i < _gridSize.y / IEntity::UNIT_HEIGHT; i++)
		{
			line[0].position = sf::Vector2f(0, i * IEntity::UNIT_HEIGHT);
			line[1].position = sf::Vector2f(_gridSize.x, i * IEntity::UNIT_HEIGHT);
			window.draw(line);
		}
	}
}

void ww::DebugMode::drawTextEntityDraw(sf::RenderWindow & window, const std::string & msg, float posX, float posY,
                                       int charSize, const sf::Color & color)
{
	if (_showTextEntityDraw)
	{	
		_ss.str("");
		_ss << msg << _simulation->getDrawHandler()->getQueueSize();
		_text.setString(_ss.str());
		_text.setPosition(posX, posY);
		_text.setCharacterSize(charSize);
		_text.setColor(color);
		window.draw(_text);
	}
}

void ww::DebugMode::drawTextVideoMode(sf::RenderWindow & window, const std::string & msg, float posX, float posY,
                                      int charSize, const sf::Color & color)
{
	if (_showTextVideoMode)
	{
		const sf::VideoMode currentVideoMode = _simulation->getSettings().getCurrentVideoMode();

		_ss.str("");
		_ss << msg << currentVideoMode.width << "x" << currentVideoMode.height;
		_text.setString(_ss.str());
		_text.setPosition(posX, posY);
		_text.setCharacterSize(charSize);
		_text.setColor(color);
		window.draw(_text);
	}
}

sf::Text & ww::DebugMode::getText()
{
	return _text;
}

void ww::DebugMode::setGridSize(const sf::Vector2f & gridSize)
{
    this->_gridSize = gridSize;
}

void ww::DebugMode::setGridSize(float width, float height)
{
    this->_gridSize.x = width;
    this->_gridSize.y = height;
}

void ww::DebugMode::setShowTextFPS(bool showTextFPS)
{
	this->_showTextFPS = showTextFPS;
}

void ww::DebugMode::setShowGrid(bool showGrid)
{
	this->_showGrid = showGrid;
}

void ww::DebugMode::setShowTextEntityDraw(bool showTextEntityDraw)
{
	this->_showTextEntityDraw = showTextEntityDraw;
}

void ww::DebugMode::setShowTextVideoMode(bool showTextVideoMode)
{
	this->_showTextVideoMode = showTextVideoMode;
}
