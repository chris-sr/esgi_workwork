/* classh header */
#include "TitleModel.h"

#include <iostream>

#include "Button.h"

const std::string ww::TitleModel::MODEL_NAME = "TitleModel";

ww::TitleModel::TitleModel()
{
	_background = new Entity();
	_startButton = new Button();
	_optionsButton = new Button();
	_quitButton = new Button();
}

ww::TitleModel::~TitleModel()
{
	delete _background;
	delete _startButton;
	delete _optionsButton;
	delete _quitButton;
	std::cout << MODEL_NAME << " destroyed !" << std::endl;
}

ww::Entity* ww::TitleModel::getBackground()
{
	return _background;
}

ww::Button* ww::TitleModel::getStartButton()
{
	return _startButton;
}

ww::Button* ww::TitleModel::getOptionsButton()
{
	return _optionsButton;
}

ww::Button* ww::TitleModel::getQuitButton()
{
	return _quitButton;
}

std::string & ww::TitleModel::getInputText()
{
	return _inputText;
}

void ww::TitleModel::setInputText(const std::string & inputText)
{
	this->_inputText = inputText;
}

//Utiliser une interface IModel pour stocker les models dans une map activeModels. 
//Les models des scenes restent vivant jusqu'au retour ‡ l'Ècran titre.
//Les models servent a la serialisation/deserialisation => save/load de l'application