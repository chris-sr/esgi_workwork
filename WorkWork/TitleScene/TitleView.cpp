/* c++ header */
#include <iostream>
#include <string>

/* class header */
#include "Simulation.h"
#include "DrawHandler.h"
#include "IScene.h"
#include "TitleView.h"
#include "TitleModel.h"

#include "IEntity.h"
#include "Button.h"

ww::TitleView::TitleView(TitleModel* model, DrawHandler* drawHandler)
{
	this->_model = model;
	this->_drawHandler = drawHandler;
}

ww::TitleView::~TitleView()
{
	std::cout << "TitleView destroyed !" << std::endl;
}

void ww::TitleView::init()
{
	_model->getBackground()->getSprite().setPosition(0, 0);

	_model->getStartButton()->setSize(2 * ww::IEntity::UNIT_WIDTH, 1 * ww::IEntity::UNIT_HEIGHT);
	_model->getStartButton()->setPosition(9 * ww::IEntity::UNIT_WIDTH, 8 * ww::IEntity::UNIT_HEIGHT);
	_model->getStartButton()->setText("Demarrer", 16, sf::Color::White);
	_model->getStartButton()->centerText();

	_model->getQuitButton()->setSize(2 * ww::IEntity::UNIT_WIDTH, 1 * ww::IEntity::UNIT_HEIGHT);
	_model->getQuitButton()->setPosition(9 * ww::IEntity::UNIT_WIDTH, 10 * ww::IEntity::UNIT_HEIGHT);
	_model->getQuitButton()->setText("Quitter", 16, sf::Color::White);
	_model->getQuitButton()->centerText();

	std::cout << "TitleView initialized !" << std::endl << std::endl;
}

void ww::TitleView::render(sf::RenderWindow & window)
{
	if (_enabled)
	{
		_drawHandler->addInDrawQueue(_model->getBackground());
		_drawHandler->addInDrawQueue(_model->getStartButton());
		_drawHandler->addInDrawQueue(_model->getQuitButton());
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