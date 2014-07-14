#ifndef WORKSPACESCENE_H
#define WORKSPACESCENE_H

/* SFML header */
#include <SFML/Graphics.hpp>

#include "AbstractScene.h"

namespace ww
{
	class WorkspaceModel;
	class WorkspaceView;

	class WorkspaceScene : public AbstractScene
	{
	private:
		WorkspaceModel* _model;
		WorkspaceView* _view;
	
	protected:

	public:
		WorkspaceScene(Simulation* simulation, WorkspaceModel* model, const sf::Vector2f & size);
		~WorkspaceScene();

		static const std::string SCENE_NAME;

		/* methode ‡ redÈfinir */
		void load();
		void eventInput(sf::RenderWindow & window, sf::Event & event);
		void update(const sf::Time & deltaTime);
		void render(sf::RenderWindow & window);
		void unload();
		void switchScene();
		/* ------------------ */

		void loadEntities();

		void eventTextEntered(sf::Event & event);
		void eventKeyPressed(sf::Event & event);
        
        void eventMouseMoved(const sf::Vector2f & mousePos);
        
        void settingButtonEntered(const sf::Vector2f & mousePos);
        void quitButtonEntered(const sf::Vector2f & mousePos);
        
        void eventMouseButtonPressed(sf::Event & event, const sf::Vector2f & mousePos);

        void mouseLeftClicked(const sf::Vector2f & mousePos);
        void mouseRightClicked(const sf::Vector2f & mousePos);

		void quitButtonLeftClicked(const sf::Vector2f & mousePos);
	};
}

#endif
