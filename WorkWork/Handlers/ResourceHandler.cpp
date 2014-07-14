#include <iostream>

#include "ResourceHandler.h"

#include "Constants.h"

ww::ResourceHandler::ResourceHandler()
{

}

ww::ResourceHandler::~ResourceHandler()
{
	std::cout << "ResourceHandler destroyed !" << std::endl;
}

void ww::ResourceHandler::addLoadError(const std::string & errorMsg)
{
	_loadErrors.push_back(errorMsg);
}

bool ww::ResourceHandler::haveLoadErrors()
{
	displayLoadErrors();
	return !_loadErrors.empty();
}

void ww::ResourceHandler::displayLoadErrors()
{
	for (int i = 0; i < _loadErrors.size(); i++)
	{
		std::cout << _loadErrors[i] << std::endl;
	}
}

void ww::ResourceHandler::clearLoadError()
{
	_loadErrors.clear();
}

bool ww::ResourceHandler::loadFont(const std::string & fontPath)
{
	if (!_fontMap[fontPath].loadFromFile(fontPath))
	{
		return false;
	}
	std::cout << "fontMap size : " << _fontMap.size() << std::endl;
	return true;
}

void ww::ResourceHandler::clearFonts()
{
	_fontMap.clear();
	std::cout << "fontMap cleared ! Size = " << _fontMap.size() << std::endl;
}

bool ww::ResourceHandler::loadTexture(const std::string & texturePath)
{
	if (!_textureMap[texturePath].loadFromFile(texturePath))
	{
		return false;
	}
	std::cout << "textureMap size : " << _textureMap.size() << std::endl;
	return true;
}

void ww::ResourceHandler::clearTextures()
{
	_textureMap.clear();
	std::cout << "textureMap cleared ! Size = " << _textureMap.size() << std::endl;
}

std::map<const std::string, sf::Font> & ww::ResourceHandler::getFontMap()
{
	return _fontMap;
}

std::map<const std::string, sf::Texture> & ww::ResourceHandler::getTextureMap()
{
	return _textureMap;
}