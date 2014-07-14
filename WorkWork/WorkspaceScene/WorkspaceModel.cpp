/* classh header */
#include "WorkspaceModel.h"

#include <iostream>

#include "TextField.h"
#include "Button.h"
#include "Tooltip.h"

const std::string ww::WorkspaceModel::MODEL_NAME = "WorkspaceModel";

ww::WorkspaceModel::WorkspaceModel()
{
	_background = new Entity();
	_factorySpace = new Entity();
	
    _textFieldCreateFactory = new ww::TextField();
    
    _settingButton = new Button();
    _quitButton = new Button();
    
    _tooltip = new Tooltip();
}

ww::WorkspaceModel::~WorkspaceModel()
{
	delete _background;
	delete _textFieldCreateFactory;
    delete _settingButton;
    delete _quitButton;
    delete _tooltip;

	std::cout << MODEL_NAME << " destroyed !" << std::endl;
}

ww::Entity* ww::WorkspaceModel::getBackground()
{
	return _background;
}

ww::Entity* ww::WorkspaceModel::getFactorySpace()
{
	return _factorySpace;
}

ww::TextField* ww::WorkspaceModel::getTextFieldCreateFactory()
{
	return _textFieldCreateFactory;
}

ww::Button* ww::WorkspaceModel::getSettingButton()
{
	return _settingButton;
}

ww::Button* ww::WorkspaceModel::getQuitButton()
{
	return _quitButton;
}

ww::Tooltip* ww::WorkspaceModel::getTooltip()
{
	return _tooltip;
}

//Utiliser une interface IModel pour stocker les models dans une map activeModels. 
//Les models des scenes restent vivant jusqu'au retour ‡ l'Ècran titre.
//Les models servent a la serialisation/deserialisation => save/load de l'application