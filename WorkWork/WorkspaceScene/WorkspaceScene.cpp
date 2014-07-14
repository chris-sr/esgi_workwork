#include <iostream>

/* class header */
#include "WorkspaceScene.h"

#include "Constants.h"
#include "Simulation.h"
#include "ResourceHandler.h"
#include "WorkspaceModel.h"
#include "WorkspaceView.h"

#include "TextField.h"
#include "Button.h"

#include "TitleScene.h"
#include "TitleModel.h"

const std::string ww::WorkspaceScene::SCENE_NAME = "WorkspaceScene";

ww::WorkspaceScene::WorkspaceScene(Simulation* simulation, WorkspaceModel* model, const sf::Vector2f & size) :
	AbstractScene(simulation, size)
{
	std::cout << std::endl << SCENE_NAME << " created !" << std::endl;

	this->_model = model;
	_view = new WorkspaceView(_model, _simulation->getDrawHandler());
}

ww::WorkspaceScene::~WorkspaceScene()
{
	std::cout << SCENE_NAME << " destroyed !" << std::endl;
	delete _view;
}

void ww::WorkspaceScene::load()
{
	std::cout << "Loading " << SCENE_NAME << " !" << std::endl;

	/* Textures */
	loadTextureSmooth(ww::File::Texture::WALLPAPERS::GRAY);
	loadTextureSmooth(ww::File::Texture::GUI);
    loadTextureSmooth(ww::File::Texture::ICONS);

	/* Fonts */
    loadFont(ww::File::Font::ARIAL);
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

void ww::WorkspaceScene::loadEntities()
{
	sf::Texture & textureWallpaper = getTexture(ww::File::Texture::WALLPAPERS::GRAY);
	sf::Texture & textureGUI = getTexture(ww::File::Texture::GUI);
    sf::Texture & textureIcons = getTexture(ww::File::Texture::ICONS);

	_model->getBackground()->getSprite().setTexture(textureWallpaper);

	_model->getFactorySpace()->getSprite().setTexture(textureGUI);
	_model->getFactorySpace()->getSprite().setTextureRect(sf::IntRect(0, 128, 192, 192));
    
    _model->getSettingButton()->getSprite().setTexture(textureIcons);
    _model->getSettingButton()->getSprite().setTextureRect(sf::IntRect(4*32, 4*32, 32, 32));
    
    _model->getQuitButton()->getSprite().setTexture(textureIcons);
    _model->getQuitButton()->getSprite().setTextureRect(sf::IntRect(0*32, 7*32, 32, 32));

	_model->getTextFieldCreateFactory()->load(textureGUI, getFont(ww::File::Font::ARIALB));
    
    _model->getTooltip()->getText().setFont(getFont(ww::File::Font::ARIAL));

	std::cout << SCENE_NAME << " loaded !" << std::endl;
}


void ww::WorkspaceScene::eventInput(sf::RenderWindow & window, sf::Event & event)
{
	//std::cout << "Input TitleScene" << std::endl;

	// rÈcupÈration de la position de la souris dans la fenÍtre
	sf::Vector2i pixelPos = sf::Mouse::getPosition(window);

	// conversion en coordonnÈes de la sf::View (camera) actuelle
	sf::Vector2f mousePos = window.mapPixelToCoords(pixelPos);

	switch (event.type)
	{
		case sf::Event::TextEntered: 
			eventTextEntered(event);
			break;

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

void ww::WorkspaceScene::eventTextEntered(sf::Event & event)
{
	TextField* textField = _model->getTextFieldCreateFactory();
	sf::Text & text = textField->getText();

	//Voir l'unicode pour empecher certains characteres...
	//Symbole sous Office Word pour recuperer les codes unicodes.
	char letter = static_cast<char>(event.text.unicode);
	std::cout << event.text.unicode << " = " << letter << std::endl;
	if (event.text.unicode != 13)
	{
		if (event.text.unicode == 8)
		{
			std::string tmp = text.getString();
			int textLength = tmp.length();
			if (textLength > 0)
			{
				tmp.erase(textLength - 1);
				text.setString(tmp);
			}
		}
		else if (textField->isLetter(letter))
		{
			text.setString(text.getString() + letter);
		}
		textField->centerText();
	}
}

void ww::WorkspaceScene::eventKeyPressed(sf::Event & event)
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

void ww::WorkspaceScene::eventMouseMoved(const sf::Vector2f & mousePos)
{
    _model->getTooltip()->setVisible(false);
    
    settingButtonEntered(mousePos);
    quitButtonEntered(mousePos);
}

void ww::WorkspaceScene::settingButtonEntered(const sf::Vector2f & mousePos)
{
    ww::Tooltip* tooltip = _model->getTooltip();
    
    if (_model->getSettingButton()->containsMouse(mousePos) &&
        _model->getSettingButton()->isVisible())
    {
        const sf::Vector2f & tooltipSize = tooltip->getRect().getSize();
        tooltip->setVisible(true);
        tooltip->getRect().setPosition(mousePos.x - tooltipSize.x / 2,
                            mousePos.y - tooltipSize.y * 2);
        tooltip->getText().setString("Options");
        tooltip->centerText();
    }
}

void ww::WorkspaceScene::quitButtonEntered(const sf::Vector2f & mousePos)
{
    ww::Tooltip* tooltip = _model->getTooltip();
    
    if (_model->getQuitButton()->containsMouse(mousePos) &&
        _model->getQuitButton()->isVisible())
    {
        const sf::Vector2f & tooltipSize = tooltip->getRect().getSize();
        tooltip->setVisible(true);
        tooltip->getRect().setPosition(mousePos.x - tooltipSize.x / 2,
                             mousePos.y - tooltipSize.y * 2);
        tooltip->getText().setString("Quitter");
        tooltip->centerText();
    }
}

void ww::WorkspaceScene::eventMouseButtonPressed(sf::Event & event, const sf::Vector2f & mousePos)
{
	std::cout << "mouse clicked x: " << mousePos.x << std::endl;
	std::cout << "mouse clicked y: " << mousePos.y << std::endl;
	
	switch (event.mouseButton.button)
	{
		case sf::Mouse::Left:
			mouseLeftClicked(mousePos);
			break;

		case sf::Mouse::Right:
			break;

		default:
			break;
	}
}

void ww::WorkspaceScene::mouseLeftClicked(const sf::Vector2f & mousePos)
{
    quitButtonLeftClicked(mousePos);
}

void ww::WorkspaceScene::mouseRightClicked(const sf::Vector2f & mousePos)
{
    
}

void ww::WorkspaceScene::quitButtonLeftClicked(const sf::Vector2f & mousePos)
{
	if (_model->getQuitButton()->isClicked(mousePos))
	{
		std::cout << "QuitButton clicked !" << std::endl;

		TitleModel* titleModel = 
			static_cast<TitleModel*>(_simulation->getActiveModels()[ww::TitleModel::MODEL_NAME]);
		if (titleModel == NULL)
		{
			titleModel = new TitleModel();
			_simulation->getActiveModels()[ww::TitleModel::MODEL_NAME] = titleModel;
		}
		///*** Modif model si besoin ***///
		///titleModel->
		///******///
		ww::IScene::state = ww::IScene::SWITCHING;
		_nextScene = new ww::TitleScene(_simulation, titleModel, sf::Vector2f(1280, 720));
	}
}

void ww::WorkspaceScene::update(const sf::Time & deltaTime)
{
	//std::cout << "Update TitleScene" << std::endl;
}

void ww::WorkspaceScene::render(sf::RenderWindow & window)
{
	//std::cout << "Render TitleScene" << std::endl;
	_view->render(window);
}

void ww::WorkspaceScene::unload()
{
	std::cout << "Unload " << SCENE_NAME << std::endl;
	_resourceHandler->clearLoadError();
	_resourceHandler->clearFonts();
	_resourceHandler->clearTextures();
}

void ww::WorkspaceScene::switchScene()
{
	if (_nextScene != NULL)
	{
		//_view->setFadingEffect();
		//if (!view->isFading())
		_simulation->switchScene(_nextScene);
	}
}

