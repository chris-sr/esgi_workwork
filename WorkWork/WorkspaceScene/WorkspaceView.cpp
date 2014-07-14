/* c++ header */
#include <iostream>
#include <string>

/* class header */
#include "Simulation.h"
#include "IScene.h"
#include "DrawHandler.h"

#include "WorkspaceView.h"
#include "WorkspaceModel.h"

#include "TextField.h"
#include "Button.h"

ww::WorkspaceView::WorkspaceView(WorkspaceModel* model, DrawHandler* drawHandler)
{
	this->_model = model;
	this->_drawHandler = drawHandler;
}

ww::WorkspaceView::~WorkspaceView()
{
	std::cout << "WorkspaceView destroyed !" << std::endl;
}

void ww::WorkspaceView::init()
{
    _model->getTooltip()->setVisible(false);
    _model->getTooltip()->getRect().setSize(sf::Vector2f(48, 16));
    _model->getTooltip()->getRect().setFillColor(sf::Color(255, 216, 0));
    _model->getTooltip()->getRect().setOutlineColor(sf::Color::Black);
    _model->getTooltip()->getRect().setOutlineThickness(1);
    _model->getTooltip()->getText().setCharacterSize(10);
    _model->getTooltip()->getText().setColor(sf::Color::Black);
    
	_model->getBackground()->setSize(20 * ww::IEntity::UNIT_WIDTH, 11.25f * ww::IEntity::UNIT_HEIGHT);
	_model->getBackground()->setPosition(0 * ww::IEntity::UNIT_WIDTH, 0 * ww::IEntity::UNIT_HEIGHT);

	_model->getFactorySpace()->setSize(3 * ww::IEntity::UNIT_WIDTH, 3 * ww::IEntity::UNIT_HEIGHT);
	_model->getFactorySpace()->setPosition(1 * ww::IEntity::UNIT_WIDTH, 1 * ww::IEntity::UNIT_HEIGHT);
    
    _model->getSettingButton()->setSize(0.5f * ww::IEntity::UNIT_WIDTH, 0.5f * ww::IEntity::UNIT_HEIGHT);
	_model->getSettingButton()->setPosition(18 * ww::IEntity::UNIT_WIDTH, 10.5f * ww::IEntity::UNIT_HEIGHT);
    
    _model->getQuitButton()->setSize(0.5f * ww::IEntity::UNIT_WIDTH, 0.5f * ww::IEntity::UNIT_HEIGHT);
	_model->getQuitButton()->setPosition(18.5f * ww::IEntity::UNIT_WIDTH, 10.5f * ww::IEntity::UNIT_HEIGHT);

	TextField* textFieldCreateFactory = _model->getTextFieldCreateFactory();
	textFieldCreateFactory->setSize(2 * ww::IEntity::UNIT_WIDTH, 1 * ww::IEntity::UNIT_HEIGHT);
	textFieldCreateFactory->setPosition(9 * ww::IEntity::UNIT_WIDTH, 5 * ww::IEntity::UNIT_HEIGHT);
	textFieldCreateFactory->centerText();
	
	sf::Text & text = textFieldCreateFactory->getText();
	text.setString(textFieldCreateFactory->getText().getString());
	text.setCharacterSize(16);
	text.setColor(sf::Color::Black);

	std::cout << "WorkspaceView initialized !" << std::endl << std::endl;
}

void ww::WorkspaceView::render(sf::RenderWindow & window)
{
	if (_enabled)
	{
		_drawHandler->addInDrawQueue(_model->getBackground());
		_drawHandler->addInDrawQueue(_model->getFactorySpace());
		_drawHandler->addInDrawQueue(_model->getTextFieldCreateFactory());
        _drawHandler->addInDrawQueue(_model->getSettingButton());
        _drawHandler->addInDrawQueue(_model->getQuitButton());
        _drawHandler->addInDrawQueue(_model->getTooltip());
		if (_visible)
		{
			//Si besoin
			//_drawHandler->sortDrawQueue();
			_drawHandler->drawExecute(window);
		}
	}
}

//GÈrer les draw avec une drawQueue au lieu de draw directement pour le problËme du premier/arriere plan
//Trier la drawQueue avec la variable drawOrder et la position y