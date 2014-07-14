#include <iostream>

/* class header */
#include "TitleScene.h"

#include "Constants.h"
#include "ResourceHandler.h"

#include "Simulation.h"
#include "TitleModel.h"
#include "TitleView.h"
#include "WorkspaceScene.h"
#include "WorkspaceModel.h"

#include "Button.h"

const std::string ww::TitleScene::SCENE_NAME = "TitleScene";

ww::TitleScene::TitleScene(Simulation* simulation, TitleModel* model, const sf::Vector2f & size) :
AbstractScene(simulation, size)
{
	std::cout << std::endl << SCENE_NAME << " created !" << std::endl;
	
	this->_model = model;
	_view = new TitleView(_model, _simulation->getDrawHandler());
}

ww::TitleScene::~TitleScene()
{
	std::cout << SCENE_NAME << " destroyed !" << std::endl;
	delete _view;
}

void ww::TitleScene::load()
{
	std::cout << "Loading " << SCENE_NAME << " !" << std::endl;

	/* Textures */
	loadTextureSmooth(ww::File::Texture::WALLPAPERS::EARTH_LANDSCAPE);
	loadTextureSmooth(ww::File::Texture::GUI);

	/* Fonts */
	loadFont(ww::File::Font::ARIALB);

	if (!haveLoadErrors())
	{
		loadEntities();
		_view->init();
		_view->setEnabled(true);
	}
	else
	{
		std::cout << SCENE_NAME << ":Error while loading !" << std::endl;
	}
}

void ww::TitleScene::loadEntities()
{
	sf::Texture & textureGUI = getTexture(ww::File::Texture::GUI);
	sf::Texture & textureWallpaper = getTexture(ww::File::Texture::WALLPAPERS::EARTH_LANDSCAPE);

	_model->getBackground()->getSprite().setTexture(textureWallpaper);
	_model->getStartButton()->load(textureGUI, getFont(ww::File::Font::ARIALB));
	_model->getQuitButton()->load(textureGUI, getFont(ww::File::Font::ARIALB));

	std::cout << SCENE_NAME << " loaded !" << std::endl;
}

void ww::TitleScene::eventInput(sf::RenderWindow & window, sf::Event & event)
{
	//std::cout << "Input TitleScene" << std::endl;

	// rÈcupÈration de la position de la souris dans la fenÍtre
	sf::Vector2i pixelPos = sf::Mouse::getPosition(window);

	// conversion en coordonnÈes de la sf::View (camera) actuelle
	sf::Vector2f mousePos = window.mapPixelToCoords(pixelPos);

	switch (event.type)
	{
		case sf::Event::KeyPressed:
			eventKeyPressed(event);
			break;

		case sf::Event::MouseMoved:
			eventMouseMoved(mousePos);
			break;

		case sf::Event::MouseButtonPressed:
			eventMouseButtonPressed(event, mousePos);
			break;

		default:
			break;
	}
}

void ww::TitleScene::eventKeyPressed(sf::Event & event)
{
	switch (event.key.code)
	{
		case sf::Keyboard::Escape:
			_simulation->getWindow().close();
			break;

		case sf::Keyboard::Return:
			
			break;

		default:
			break;
	}
}

void ww::TitleScene::eventMouseMoved(sf::Vector2f & mousePos)
{
	startButtonMouseOver(mousePos);
	quitButtonMouseOver(mousePos);
}

void ww::TitleScene::startButtonMouseOver(sf::Vector2f & mousePos)
{
	ww::Button* startButton = _model->getStartButton();
	sf::Text & textButton = startButton->getText();
	
	startButton->containsMouse(mousePos) ? 
		textButton.setColor(sf::Color::Yellow) : textButton.setColor(sf::Color::White);
}

void ww::TitleScene::quitButtonMouseOver(sf::Vector2f & mousePos)
{
	ww::Button* quitButton = _model->getQuitButton();
	sf::Text & textButton = quitButton->getText();
	
	quitButton->containsMouse(mousePos) ? 
		textButton.setColor(sf::Color::Yellow) : textButton.setColor(sf::Color::White);
}

void ww::TitleScene::eventMouseButtonPressed(sf::Event & event, sf::Vector2f & mousePos)
{
	std::cout << "mouse clicked x: " << mousePos.x << std::endl;
	std::cout << "mouse clicked y: " << mousePos.y << std::endl;
	
	switch (event.mouseButton.button)
	{
		case sf::Mouse::Left:
			startButtonLeftClicked(mousePos);
			quitButtonLeftClicked(mousePos);
			break;

		case sf::Mouse::Right:
			break;

		default:
			break;
	}
}

void ww::TitleScene::startButtonLeftClicked(sf::Vector2f & mousePos)
{
	if (_model->getStartButton()->isClicked(mousePos))
	{
		std::cout << "StartButton clicked !" << std::endl;
		//_model->getStartButton().setVisible(false);
		//_model->getQuitButton().setVisible(true);
		WorkspaceModel* workspaceModel =  static_cast<WorkspaceModel*>(
			_simulation->getActiveModels()[ww::WorkspaceModel::MODEL_NAME]);
		if (workspaceModel == NULL)
		{
			workspaceModel = new WorkspaceModel();
			_simulation->getActiveModels()[ww::WorkspaceModel::MODEL_NAME] = workspaceModel;
		}
		///*** Modif model si besoin ***///
		///workspaceModel->
		///******///
		ww::IScene::state = ww::IScene::SWITCHING;
		_nextScene = new ww::WorkspaceScene(_simulation, workspaceModel, sf::Vector2f(1280, 720));
	}
}

void ww::TitleScene::quitButtonLeftClicked(sf::Vector2f & mousePos)
{
	if (_model->getQuitButton()->isClicked(mousePos))
	{
		std::cout << "QuitButton clicked !" << std::endl;

		_simulation->getWindow().close();
	}
}

void ww::TitleScene::update(const sf::Time & deltaTime)
{
	//std::cout << "Update TitleScene" << std::endl;
}

void ww::TitleScene::render(sf::RenderWindow & window)
{
	//std::cout << "Render TitleScene" << std::endl;
	_view->render(window);
}

void ww::TitleScene::unload()
{
	std::cout << "Unload " << ww::TitleScene::SCENE_NAME << " !" << std::endl;
	_resourceHandler->clearLoadError();
	//Pause probleme a avoir dans situation reel avec changement de scene
	_resourceHandler->clearFonts();
	_resourceHandler->clearTextures();
}

void ww::TitleScene::switchScene()
{
	if (_nextScene != NULL)
	{
		//_view->setFadingEffect();
		//if (!view->isFading())
		_simulation->switchScene(_nextScene);
	}
}
