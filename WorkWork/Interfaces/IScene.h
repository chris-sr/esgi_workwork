#ifndef ISCENE_H
#define ISCENE_H

#include <SFML/Graphics.hpp>

namespace ww
{
	class IScene
	{
	public:
		/* Pour forcer l'appel du destructeur de la classe enfant */
		virtual ~IScene() {};

		virtual void load() = 0;
		virtual void eventInput(sf::RenderWindow & window, sf::Event & event) = 0;
		virtual void update(const sf::Time & deltaTime) = 0;
		virtual void render(sf::RenderWindow & window) = 0;
		virtual void unload() = 0;
		virtual void switchScene() = 0;

		static const float UNIT;

		enum STATE {RUNNING, SWITCHING};
		static IScene::STATE state;
	};
}

#endif