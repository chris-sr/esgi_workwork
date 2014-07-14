#include <iostream>

#include "Simulation.h"
#include "Constants.h"

#include "ResourceHandler.h"
#include "DrawHandler.h"
#include "TitleScene.h"
#include "DebugMode.h"

#include "IModel.h"
#include "TitleModel.h"
#include "Entity.h"

#include "Button.h"

ww::Simulation::Simulation()
{
	//Important de l'allouer dans le constructeur ‡ cause
	//du DebugMode qui charge le font avec le resourceHandler
	_resourceHandler = new ResourceHandler();
	
	_drawHandler = new DrawHandler();
	_currentScene = NULL;

	_debugMode = NULL;
	_fps = 0;
}

ww::Simulation::~Simulation()
{
	delete _currentScene;
	delete _drawHandler,
	delete _debugMode;
	delete _resourceHandler;
	clearActiveModels();
}

void ww::Simulation::run()
{
	std::cout << "\nApp Running !" << std::endl;
    
    std::cout << "\nResource Path = \n" << resourcePath() << std::endl;

	/*_window.create(_settings.getCurrentVideoMode(), "Work Work!", 
		_settings.isFullscreen() ? sf::Style::Fullscreen : sf::Style::Titlebar | sf::Style::Close);*/

	_window.create(_settings.getCurrentVideoMode(), "Work Work!", 
		_settings.isFullscreen() ? sf::Style::Fullscreen : sf::Style::Default);

	_window.setFramerateLimit(60);
    
    sf::Vector2f cameraSize(1280, 720);
    _camera.setSize(cameraSize);
    _camera.setCenter(sf::Vector2f(cameraSize.x / 2, cameraSize.y / 2));
	_window.setView(_camera);

	_activeModels[ww::TitleModel::MODEL_NAME] = new TitleModel();
	TitleModel* titleModel = 
		static_cast<TitleModel*>(_activeModels[ww::TitleModel::MODEL_NAME]);

	_currentScene = new TitleScene(this, titleModel, sf::Vector2f(1280, 720));
	_currentScene->load();

	sf::Clock deltaClock;
    while (_window.isOpen())
    {
		sf::Time deltaTime = deltaClock.restart();
		_fps = 1.f / deltaTime.asSeconds();
		
		sf::Event event;

		while (_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				_window.close();
			
			if (ww::IScene::state == ww::IScene::RUNNING)
			{
				_currentScene->eventInput(_window, event);
				_currentScene->update(deltaTime);
			}
		}
        _window.clear();
		_drawHandler->clearDrawQueue();
		_currentScene->render(_window);

		if (_debugMode != NULL)
			_debugMode->renderDebug(_window);

        _window.display();
		
		if (ww::IScene::state == ww::IScene::SWITCHING)
			_currentScene->switchScene();
    }
}

void ww::Simulation::switchScene(AbstractScene* nextScene)
{
	_currentScene->unload();
	delete _currentScene;

	if (_debugMode != NULL)
		_debugMode->loadFont(ww::File::Font::ARIALB);

	this->_currentScene = nextScene;
	_currentScene->load();
	ww::IScene::state = ww::IScene::RUNNING;
}

//*** DEBUG ***//

void ww::Simulation::setShowTextFPS(bool showTextFPS)
{
	if (_debugMode == NULL)
		_debugMode = new DebugMode(this);

	_debugMode->setShowTextFPS(showTextFPS);
	_debugMode->loadFont(ww::File::Font::ARIALB);
}

void ww::Simulation::setShowGrid(bool showGrid)
{
	if (_debugMode == NULL)
		_debugMode = new DebugMode(this);

	_debugMode->setShowGrid(showGrid);
    _debugMode->setGridSize(sf::Vector2f(1280, 720));
}

void ww::Simulation::setShowTextEntityDraw(bool showTextDrawNb)
{
	if (_debugMode == NULL)
		_debugMode = new DebugMode(this);

	_debugMode->setShowTextEntityDraw(showTextDrawNb);
	_debugMode->loadFont(ww::File::Font::ARIALB);
}

void ww::Simulation::setShowTextVideoMode(bool showTextVideoMode)
{
	if (_debugMode == NULL)
		_debugMode = new DebugMode(this);

	_debugMode->setShowTextVideoMode(showTextVideoMode);
	_debugMode->loadFont(ww::File::Font::ARIALB);
}

//*** FIN DEBUG ***//

ww::ResourceHandler* ww::Simulation::getResourceHandler()
{
	return _resourceHandler;
}

ww::DrawHandler* ww::Simulation::getDrawHandler()
{
	return _drawHandler;
}

sf::RenderWindow & ww::Simulation::getWindow()
{
	return _window;
}

sf::View & ww::Simulation::getCamera()
{
	return _camera;
}

std::map<const std::string, ww::IModel*> & ww::Simulation::getActiveModels()
{
	return _activeModels;
}

void ww::Simulation::clearActiveModels()
{
	std::map<const std::string, IModel*>::iterator it;

	for (it =_activeModels.begin(); it != _activeModels.end(); it++)
		delete it->second;

	_activeModels.clear();
}

ww::Settings & ww::Simulation::getSettings()
{
	return _settings;
}

float ww::Simulation::getFPS()
{
	return _fps;
}