#ifndef TITLESCENE_H
#define TITLESCENE_H

/* SFML header */
#include <SFML/Graphics.hpp>

#include "AbstractScene.h"

namespace ww
{
	class TitleModel;
	class TitleView;
	class Button;

	class TitleScene : public AbstractScene
	{
	private:
		TitleModel* _model;
		TitleView* _view;

		void loadEntities();
		void initModel();

		void eventKeyPressed(sf::Event & event);
		void eventMouseMoved(sf::Vector2f & mousePos);
		void eventMouseButtonPressed(sf::Event & event, sf::Vector2f & mousePos);

		void startButtonMouseOver(sf::Vector2f & mousePos);
		void quitButtonMouseOver(sf::Vector2f & mousePos);

		void startButtonLeftClicked(sf::Vector2f & mousePos);
		void quitButtonLeftClicked(sf::Vector2f & mousePos);
	
	protected:

	public:
		TitleScene(Simulation* simulation, TitleModel* model, const sf::Vector2f & size);
		~TitleScene();

		static const std::string SCENE_NAME;

		/* methode ‡ redÈfinir */
		void load();
		void eventInput(sf::RenderWindow & window, sf::Event & event);
		void update(const sf::Time & deltaTime);
		void render(sf::RenderWindow & window);
		void unload();
		void switchScene();
		/* ------------------ */
	};
}

#endif
