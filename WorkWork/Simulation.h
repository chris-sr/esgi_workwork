#ifndef SIMULATION_H
#define SIMULATION_H

#include <map>

#include <SFML/Graphics.hpp>

#include "Settings.h"

namespace ww
{
	class AbstractScene;
	class ResourceHandler;
	class DrawHandler;
	class IModel;
	class IEntity;
	class DebugMode;

	class Simulation
	{
	private:
		ResourceHandler* _resourceHandler;
		DrawHandler* _drawHandler;

		sf::RenderWindow _window;
		sf::View _camera;

		AbstractScene* _currentScene;
		std::map<const std::string, IModel*> _activeModels;
		
		Settings _settings;

		DebugMode* _debugMode;
		float _fps;
	
	protected:

	public:
		Simulation();
		~Simulation();

		void run();
		void switchScene(AbstractScene* currentScene);

		static const float SCENE_WIDTH;
		static const float SCENE_HEIGHT;

		//**** Debug ****//
		void setShowTextFPS(bool showTextFPS);
		void setShowGrid(bool showGrid);
		void setShowTextEntityDraw(bool showTextEntityDraw);
		void setShowTextVideoMode(bool showTextVideoMode);
		/***  ***/

		ResourceHandler* getResourceHandler();
		DrawHandler* getDrawHandler();
		
		sf::RenderWindow & getWindow();
		sf::View & getCamera();

		std::map<const std::string, IModel*> & getActiveModels();
		void clearActiveModels();
		
		Settings & getSettings();

		float getFPS();
	};

}

#endif
