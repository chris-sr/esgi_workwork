/* class header */
#include "AbstractScene.h"

#include "Constants.h"
#include "IModel.h"
#include "Simulation.h"
#include "ResourceHandler.h"

const float ww::IScene::UNIT = 64;

ww::IScene::STATE ww::IScene::state = IScene::RUNNING;

ww::AbstractScene::AbstractScene(Simulation* simulation, const sf::Vector2f & size)
{
	this->_simulation = simulation;
	this->_resourceHandler = _simulation->getResourceHandler();
	this->_nextScene = NULL;
    
    this->_size = size;
}

ww::AbstractScene::~AbstractScene()
{
	
}

void ww::AbstractScene::load()
{

}

void ww::AbstractScene::eventInput(sf::RenderWindow & window, sf::Event & event)
{

}

void ww::AbstractScene::update(const sf::Time & deltaTime)
{

}

void ww::AbstractScene::render(sf::RenderWindow & window)
{

}

void ww::AbstractScene::unload()
{

}

void ww::AbstractScene::switchScene()
{

}

void ww::AbstractScene::loadFont(const std::string & fontPath)
{
	if (!_resourceHandler->loadFont(fontPath))
	{
		_resourceHandler->addLoadError("Error loading font file: " + fontPath);
	}
}

void ww::AbstractScene::loadTexture(const std::string & texturePath)
{
	if (!_resourceHandler->loadTexture(texturePath))
	{
		_resourceHandler->addLoadError("Error loading texture file: " + texturePath);
	}
}

void ww::AbstractScene::loadTextureSmooth(const std::string & texturePath)
{
	if (!_resourceHandler->loadTexture(texturePath))
	{
		_resourceHandler->addLoadError("Error loading texture file: " + texturePath);
	}
	else
	{
		getTexture(texturePath).setSmooth(true);
	}
}

bool ww::AbstractScene::haveLoadErrors()
{
	return _resourceHandler->haveLoadErrors();
}

sf::Font & ww::AbstractScene::getFont(const std::string & fontPath)
{
	return _resourceHandler->getFontMap()[fontPath];
}

sf::Texture & ww::AbstractScene::getTexture(const std::string & texturePath)
{
	return _resourceHandler->getTextureMap()[texturePath];
}

sf::Vector2f & ww::AbstractScene::getSize()
{
    return _size;
}

void ww::AbstractScene::setSize(float width, float height)
{
    this->_size.x = width;
    this->_size.y = height;
}

void ww::AbstractScene::setSize(const sf::Vector2f & size)
{
    this->_size = size;
}